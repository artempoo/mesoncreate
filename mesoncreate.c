#include <stdio.h>

#include "src/utility.h"

int main(int argc, char** argv, char* envp[]) {
  (void)argc;
  (void)argv;
  // создать строки для Makefile
  // сохранить файл
  // проверить

  printf("%s\n", get_name_app(envp));

  return 0;
}
