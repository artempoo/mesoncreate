#include "utility.h"

#include <stdbool.h>
#include <stdio.h>
#include <string.h>

char* get_name_app(char* envp[], char* PWD_DIR_NAME) {
  const char* PWD_ATTR_ENVP = "PWD=";

  int index_envp = 0;
  while (envp[index_envp] != NULL) {
    if (strncmp(PWD_ATTR_ENVP, envp[index_envp], strlen(PWD_ATTR_ENVP)) == 0) {
      PWD_DIR_NAME = (strchr(envp[index_envp], '=') + 1);
      break;
    }
    index_envp++;
  }

  char* token = strtok(PWD_DIR_NAME, "/");
  while (token != NULL) {
    PWD_DIR_NAME = token;
    token = strtok(NULL, "/");
  }

  return PWD_DIR_NAME;
}

bool create_makefile(char* app_name) {
  FILE* fptr = fopen("Makefile", "w");
  if (fptr == NULL) {
    fprintf(stderr, "Ошибка, файл не создан");
    return false;
  }

  fprintf(fptr, "all:\n\t");
  fprintf(fptr, "meson compile -C build && ./build/");
  fprintf(fptr, "%s\n\n", app_name);

  fprintf(fptr, "setup:\n\t");
  fprintf(fptr, "meson setup build\n\n");

  fprintf(fptr, "build:\n\t");
  fprintf(fptr, "meson compile -C build\n\n");

  fprintf(fptr, "clean:\n\t");
  fprintf(fptr, "rm -rf .cache && rm -rf build/\n\n");

  fprintf(fptr, "run:\n\t");
  fprintf(fptr, "./build/");
  fprintf(fptr, "%s\n\n", app_name);

  fprintf(fptr, ".PHONY: all build\n");

  fclose(fptr);

  printf("\033[32m");
  printf("Создал Makefile\n");
  printf("\033[0m");

  return true;
}

bool create_clang_format(void) {
  FILE* fptr = fopen(".clang-format", "w");
  if (fptr == NULL) {
    fprintf(stderr, "Ошибка, файл не создан");
    return false;
  }

  fprintf(fptr, "BasedOnStyle: Google\n");
  fprintf(fptr, "IndentWidth: 2\n");
  fprintf(fptr, "ColumnLimit: 0\n");

  fclose(fptr);

  printf("\033[32m");
  printf("Создал .clang-format\n");
  printf("\033[0m");

  return true;
}

bool create_gitignore(void) {
  FILE* fptr = fopen(".gitignore", "w");
  if (fptr == NULL) {
    fprintf(stderr, "Ошибка, файл не создан");
    return false;
  }

  fprintf(fptr, ".cache/\n");
  fprintf(fptr, "build/\n");

  fclose(fptr);

  printf("\033[32m");
  printf("Создал .gitignore\n");
  printf("\033[0m");

  return true;
}
