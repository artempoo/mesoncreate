#include <stdbool.h>
#include <stdio.h>

#include "src/utility.h"

int main(int argc, char** argv, char* envp[]) {
  (void)argc;
  (void)argv;

  char* app_name = "";
  char* r = get_name_app(envp, app_name);
  app_name = r;

  bool makefile = create_makefile(app_name);
  if (!makefile) {
    fprintf(stderr, "Неудалось создать Makefile\n");
    return 1;
  }

  bool clangformat = create_clang_format();
  if (!clangformat) {
    fprintf(stderr, "Неудалось создать .clang-format\n");
    return 1;
  }

  return 0;
}
