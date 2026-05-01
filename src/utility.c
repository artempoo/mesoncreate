#include "utility.h"

#include <string.h>

char* get_name_app(char* envp[]) {
  const char* PWD_ATTR_ENVP = "PWD=";
  char* PWD_DIR_NAME = "";

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
