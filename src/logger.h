#include <stdio.h>
#include <string.h>

void log_api(const char *url, const char *method) {
  printf("[%s] %s\n", method, url);
}