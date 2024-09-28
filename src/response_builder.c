#include <microhttpd.h>
#include "headers/utils.h"

struct MHD_Response *HTTP_build_response_JSON(const char *message) {
  struct MHD_Response *response;

  response = MHD_create_response_from_buffer(strlen(message), (void *)message, MHD_RESPMEM_PERSISTENT);

  if (!response)
    return NULL;

  MHD_add_response_header(response, "Content-Type", "application/json");
  MHD_add_response_header(response, "Access-Control-Allow-Origin", "*");

  return response;
}