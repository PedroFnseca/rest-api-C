#include <stdio.h>
#include <string.h>
#include <microhttpd.h>
#include "logger.h"

enum MHD_Result default_handler(void *cls, struct MHD_Connection *connection, const char *url,
                                const char *method, const char *version, const char *upload_data,
                                size_t *upload_data_size, void **con_cls) {
  struct MHD_Response *response;
  char *url_str = (char *)url;
  char *method_str = (char *)method;
  int ret;

  log_api(url_str, method_str);

  response = MHD_create_response_from_buffer(strlen(url_str), (void *)url_str, MHD_RESPMEM_PERSISTENT);

  if (!response)
    return MHD_NO;

  ret = MHD_queue_response(connection, MHD_HTTP_OK, response);
  MHD_destroy_response(response);

  return ret;
}