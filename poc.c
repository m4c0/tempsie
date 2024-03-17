#include <stdio.h>

#define TEMPSIE_IMPLEMENTATION
#define TEMPSIE_ERROR puts
#include "tempsie.h"

int main(int argc, char ** argv) {
  char buf[1024];
  if (0 != tempsie_get_temp_filename("tempsie", buf, sizeof(buf))) {
    puts("fail to get temp filename");
    return 1;
  }
  printf("temp filename: [%s]\n", buf);
  return 0;
}
