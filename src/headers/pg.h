#ifndef PG_H
#define PG_H

#include <libpq-fe.h>

#define database "*****"
#define user "*****"
#define password "*****"
#define host "***.***.***.***"
#define port "****"

char *executeQueryToJson(const char *query);

char *formatResultAsJson(PGresult *result);

#endif