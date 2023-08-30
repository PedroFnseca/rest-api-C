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

char *simple_message(const char *message_str) {
  char *formatted_message = NULL;

  size_t formatted_message_size = strlen(message_str) + 20;
  formatted_message = (char *)malloc(formatted_message_size);

  if (formatted_message) {
    snprintf(formatted_message, formatted_message_size, "{\"message\": \"%s\"}", message_str);
  }

  return formatted_message;
}

bool is_valid_route(const char *url, char *route) {
  return strstr(url, route) != NULL;
}

bool is_valid_method(const char *method, char *valid_method) {
  return strcmp(method, valid_method) == 0;
}