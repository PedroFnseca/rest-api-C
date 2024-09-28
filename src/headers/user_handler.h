#include "headers/pg.h"
#include <string.h>
#include <stdio.h>

HTTP_response get_all(const char *url) {
  const char *query = "SELECT * FROM users";

  char *result = executeQueryToJson(query);

  return validate_result(result);
}

HTTP_response get_one(const char *user_id) {
  if (user_id == NULL) {
    return (HTTP_response){
      .body = simple_message("No user id provided"),
      .status = BAD_REQUEST
    };
  }

  char query[64];
  snprintf(query, sizeof(query), "SELECT * FROM users WHERE id = %s", user_id);

  char *result = executeQueryToJson(query);

  return validate_result(result);
}

HTTP_response create(const char *body) {
  if (body == NULL) {
    return (HTTP_response){
      .body = simple_message("No body provided"),
      .status = BAD_REQUEST
    };
  }

  char query[256];
  snprintf(query, sizeof(query), "INSERT INTO users (name, email) VALUES ('%s', '%s')", "name", "email");

  char *result = executeQueryToJson(query);

  return validate_result(result);
}

HTTP_response update(const char *user_id, const char *body) {
  if (user_id == NULL) {
    return (HTTP_response){
      .body = simple_message("No user id provided"),
      .status = BAD_REQUEST
    };
  }
  
  if (body == NULL) {
    return (HTTP_response){
      .body = simple_message("No body provided"),
      .status = BAD_REQUEST
    };
  }

  char query[256];
  snprintf(query, sizeof(query), "UPDATE users SET name = '%s', email = '%s' WHERE id = %s", "name", "email", user_id);

  char *result = executeQueryToJson(query);

  return validate_result(result);
}

HTTP_response drop(const char *user_id) {
  char query[64];
  snprintf(query, sizeof(query), "DELETE FROM users WHERE id = %s", user_id);

  char *result = executeQueryToJson(query);

  return validate_result(result);
}

HTTP_response user_router(const char *url, const char *method, const char *body){
  char *user_id = strstr(url, "/users/");
  if (user_id != NULL) {
    user_id += strlen("/users/");
  }
  
  if (validate_method(method, "GET")) {
      if(user_id == NULL){
        return get_all(url);
      } else {
        return get_one(user_id);
      }
  }
  
  if (validate_method(method, "POST")) {
    return create(body);
  }
  
  if (validate_method(method, "PUT")) {
    return update(user_id, body);
  } 
  
  if (validate_method(method, "DELETE")) {
    return drop(user_id);
  }

  return (HTTP_response){
    .body = simple_message("Not implemented"),
    .status = NOT_IMPLEMENTED
  };
}