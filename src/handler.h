#include "response_builder.h"

void log_api(const char *url, const char *method) {
  printf("[%s] %s\n", method, url);
}

enum MHD_Result default_handler(void *cls, struct MHD_Connection *connection, const char *url,
                                const char *method, const char *version, const char *upload_data,
                                size_t *upload_data_size, void **con_cls) {
  char *url_str = (char *)url;
  char *method_str = (char *)method;
  int ret;

  struct MHD_Response *response;
  HTTP_status status;
  char *response_body = NULL;

  log_api(url_str, method_str);

  if (strcmp(url_str, "/") == 0) {
    response_body = simple_message("Hello, world!");
    status = OK;
  } else if (strcmp(url_str, "/users") == 0) {
    // mandar para modulo de usuarios
    response_body = simple_message("Sorry, this endpoint is not implemented yet");
    status = OK;
  } else {
    response_body = simple_message("Not found");
    status = NOT_FOUND;
  }

  response = HTTP_build_response_JSON(response_body, status);

  if (!response)
    return MHD_NO;

  ret = MHD_queue_response(connection, status, response);
  MHD_destroy_response(response);

  return ret;
}