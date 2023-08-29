#include <stdio.h>
#include <string.h>

void log_api(const char *url, const char *method) {
  char *color;

  if (strcmp(method, "GET") == 0) {
    color = "\033[0;32m";
  } else if (strcmp(method, "POST") == 0) {
    color = "\033[0;33m";
  } else if (strcmp(method, "PUT") == 0) {
    color = "\033[0;34m";
  } else if (strcmp(method, "DELETE") == 0) {
    color = "\033[0;35m";
  } else {
    color = "\033[0;36m";
  }

  printf("%s[%s] %s -> %s\n", color, method, url);
}