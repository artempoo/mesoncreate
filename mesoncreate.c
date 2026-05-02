#include <errno.h>
#include <stdbool.h>
#include <stdio.h>
#include <string.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <unistd.h>

#include "src/utility.h"

int launch_prog(char** args) {
  pid_t pid = fork();
  if (pid == -1) {
    printf("Fork не создал новый процесс, ошибка\n");
    return 1;
  } else if (pid == 0) {
    execvp(args[0], args);

    // дочерний процесс
    perror("exec failed");
    return 1;
  } else if (pid > 0) {
    wait(NULL);  // Ждем завершения дочернего процесса
  }

  return 0;
}

int main(int argc, char** argv, char* envp[]) {
  (void)argc;
  (void)argv;

  char* args_m_init[] = {"meson", "init", NULL};
  launch_prog(args_m_init);

  char* args_m_setup[] = {"meson", "setup", "build", NULL};
  launch_prog(args_m_setup);

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

  bool gitignore = create_gitignore();
  if (!gitignore) {
    fprintf(stderr, "Неудалось создать .clangformat\n");
    return 1;
  }

  char* args_make[] = {"make", NULL};
  launch_prog(args_make);

  printf("\033[32m");
  fprintf(stdout, "Сборка готова к работе!\n");
  printf("\033[0m");

  return 0;
}
