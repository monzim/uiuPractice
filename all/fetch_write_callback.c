#include "fetch_write_callback.h"

#include <stdio.h>
#include <string.h>

size_t fetchWriteCallback(void *ptr, size_t size, size_t nmemb, void *userdata) {
  size_t total_size = size * nmemb;
  char *buffer = (char *)userdata;

  // Check if buffer size is exceeded
  // TODO: CHECK FILE BUFFER SIZE
  if (total_size >= 2024) {
    fprintf(stderr, "Buffer size exceeded\n");
    return 0;
  }

  // Copy fetched data to buffer
  memcpy(buffer, ptr, total_size);

  buffer[total_size] = '\0';

  return total_size;
}
