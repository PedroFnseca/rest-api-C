#ifndef RESPONSE_BUILDER_H
#define RESPONSE_BUILDER_H

#include <microhttpd.h>
#include "utils.h"

struct MHD_Response *HTTP_build_response_JSON(const char *message);

#endif
