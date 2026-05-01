#ifndef UTILITY_H
#define UTILITY_H

#include <stdbool.h>

char* get_name_app(char* envp[], char* PWD_DIR_NAME);
bool create_makefile(char* app_name);
bool create_clang_format(void);

#endif
