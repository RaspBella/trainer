#include <stdlib.h>
#include <stdio.h>
#include "../crs.h"
#include "../utils.h"

#include "modes.h"

enum input_mode input_mode;
enum timing_mode timing_mode;
enum timer timer;
enum quiz_mode quiz_mode;

struct line {
  const char *name;
  const char **codes;
};

#define LINE(NAME, ...) (struct line) { \
  .name = NAME, \
  .codes = (const char *[]){ __VA_ARGS__, NULL } \
},

struct line lines[] = {
#include "lines.def"
};

int main(void) {
  printf("Lines:\n");

  for (int i = 0; i < ARRAY_LEN(lines); ++i) {
    printf("  %s:\n", lines[i].name);

    for (int j = 0; lines[i].codes[j]; ++j) {
      printf("    %s\n", lines[i].codes[j]);
    }
  }
}
