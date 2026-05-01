#include <stdbool.h>
#include <stdio.h>

#include "src/utility.h"

int main(int argc, char** argv, char* envp[]) {
  (void)argc;
  (void)argv;

  char* app_name = "";
  char* r = get_name_app(envp, app_name);
  app_name = r;

  bool res = create_makefile(app_name);
  if (!res) {
    fprintf(stderr, "Неудалось создать Makefile\n");
    return 1;
  }

  return 0;
}
