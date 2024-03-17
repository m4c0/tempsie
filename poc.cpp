#pragma leco tool
import silog;

#define TEMPSIE_IMPLEMENTATION
#define TEMPSIE_ERROR(x) silog::log(silog::error, "Error: %s", (x))
#include "tempsie.h"

int main() {
  char buf[10240];
  if (!tempsie_get_temp_filename("tempsie", buf, sizeof(buf))) {
    silog::log(silog::info, "Failed to get temp filename");
    return 1;
  }
  silog::log(silog::info, "Temp filename: [%s]", buf);
}
