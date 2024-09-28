#ifndef UTILS_H
#define UTILS_H

#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <stdbool.h>

typedef enum {
  OK = 200,
  BAD_REQUEST = 400,
  NOT_FOUND = 404,
  INTERNAL_SERVER_ERROR = 500,
  NOT_IMPLEMENTED = 501
} HTTP_status;

typedef struct {
  char *body;
  HTTP_status status;
} HTTP_response;

typedef struct {
  int id;
  char *name;
  char *email;
} USER;

char *simple_message(const char *message_str);

HTTP_response validate_result(char *result);

bool validate_method(const char *method, char *valid_method);

bool validate_route(const char *url, char *route);

#endif