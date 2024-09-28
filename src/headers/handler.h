#ifndef HANDLER_H
#define HANDLER_H

#include <setjmp.h>

extern jmp_buf exceptionBuffer;

#define TRY if (setjmp(exceptionBuffer) == 0)
#define CATCH else

void log_api(const char *url, const char *method);

enum MHD_Result default_handler(
  void *cls, struct MHD_Connection *connection, 
  const char *url, const char *method, const char *version,
  const char *upload_data, size_t *upload_data_size, void **con_cls);

#endif