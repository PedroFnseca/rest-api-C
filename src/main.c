#include <stdio.h>
#include <string.h>
#include <microhttpd.h>
#include "handler.h"

#define PORT 8080

int main() {
  printf("Starting server on port %d\n", PORT);

  struct MHD_Daemon *daemon;

  daemon = MHD_start_daemon(MHD_USE_THREAD_PER_CONNECTION, PORT, NULL, NULL,
                            &default_handler, NULL, MHD_OPTION_END);
  if (!daemon)
    return 1;

  getchar();

  MHD_stop_daemon(daemon);

  return 0;
}
