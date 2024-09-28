#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <libpq-fe.h>
#include "headers/pg.h"

char *executeQueryToJson(const char *query) {
    PGconn *conn = PQconnectdb(
        "user=" user
        " password=" password
        " dbname=" database
        " host=" host
        " port=" port
    );

    if (PQstatus(conn) != CONNECTION_OK) {
        fprintf(stderr, "Connection to database failed: %s", PQerrorMessage(conn));
        PQfinish(conn);
        return NULL;
    }

    PGresult *result = PQexec(conn, query);

    if (PQresultStatus(result) != PGRES_TUPLES_OK) {
        fprintf(stderr, "Query execution failed: %s", PQerrorMessage(conn));
        PQclear(result);
        PQfinish(conn);
        return NULL;
    }

    char *jsonResult = formatResultAsJson(result);

    PQclear(result);
    PQfinish(conn);

    return jsonResult;
}

char *formatResultAsJson(PGresult *result) {
    int numFields = PQnfields(result);
    int numRows = PQntuples(result);

    // Calcula o tamanho total necessário para a string JSON -> para não estourar o buffer
    int totalSize = numRows * (2 + numFields * 256) + numRows - 1 + 3;
    // Cada campo contribui com pelo menos 256 caracteres, 2 para aspas e 1 para vírgula
    // numRows - 1 é para as vírgulas entre objetos JSON
    // 3 é para as chaves finais e terminador de string

    char *json = (char *)malloc(totalSize);
    json[0] = '\0';

    if (numRows == 0) {
        strcat(json, "[]");
        return json;
    }

    for (int i = 0; i < numRows; ++i) {
        strcat(json, "{");
        for (int j = 0; j < numFields; ++j) {
            if (j > 0) strcat(json, ",");
            char *fieldName = PQfname(result, j);
            char *fieldValue = PQgetvalue(result, i, j);

            strcat(json, "\"");
            strncat(json, fieldName, totalSize - strlen(json) - 5);
            strcat(json, "\":\"");
            strncat(json, fieldValue, totalSize - strlen(json) - 5);
            strcat(json, "\"");
        }
        strcat(json, "}");
        if (i < numRows - 1) strcat(json, ",");
    }

    return json;
}
