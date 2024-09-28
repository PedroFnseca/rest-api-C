#ifndef USER_HANDLER_H
#define USER_HANDLER_H

#include "utils.h"

HTTP_response get_all(const char *url);

HTTP_response get_one(const char *user_id);

HTTP_response create(const char *body);

HTTP_response update(const char *user_id, const char *body);

HTTP_response drop(const char *user_id);

HTTP_response user_router(const char *url, const char *method, const char *body);

#endif