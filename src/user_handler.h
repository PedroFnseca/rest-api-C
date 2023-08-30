#include "pg.h"
#include <string.h>
#include <stdio.h>

HTTP_response get_all(const char *url) {
  const char *query = "SELECT * FROM users";

  char *result = executeQueryToJson(query);

  if (result == NULL) {
    return (HTTP_response){
      .body = simple_message("Internal server error"),
      .status = INTERNAL_SERVER_ERROR
    };
  }

  return (HTTP_response){
    .body = result,
    .status = OK
  };
}

HTTP_response get_one(const char *user_id) {
  char query[64];
  snprintf(query, sizeof(query), "SELECT * FROM users WHERE id = %s", user_id);

  char *result = executeQueryToJson(query);

  if (result == NULL) {
    return (HTTP_response){
      .body = simple_message("Internal server error"),
      .status = INTERNAL_SERVER_ERROR
    };
  }

  return (HTTP_response){
    .body = result,
    .status = OK
  };
}

HTTP_response create(const char *body) {
  return (HTTP_response){
    .body = simple_message("create"),
    .status = OK
  };
}

HTTP_response update(const char *user_id, const char *body) {
  return (HTTP_response){
    .body = simple_message("update"),
    .status = OK
  };
}

HTTP_response drop(const char *user_id) {
  return (HTTP_response){
    .body = simple_message("drop"),
    .status = OK
  };
}

HTTP_response user_router(const char *url, const char *method, const char *body){
  char *user_id = strstr(url, "/users/");
  if (user_id != NULL) {
    user_id += strlen("/users/");
  }
  
  if (is_valid_method(method, "GET")) {
      if(user_id == NULL){
        return get_all(url);
      } else {
        return get_one(user_id);
      }
  }
  
  if (is_valid_method(method, "POST")) {
    return create(body);
  }
  
  if (is_valid_method(method, "PUT")) {
    return update(user_id, body);
  } 
  
  if (is_valid_method(method, "DELETE")) {
    return drop(user_id);
  }

  return (HTTP_response){
    .body = simple_message("Not implemented"),
    .status = NOT_IMPLEMENTED
  };
}