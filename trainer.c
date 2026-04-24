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

  for (int l = 0; l < ARRAY_LEN(lines); ++l) {
    printf("  %s:\n", lines[l].name);

    for (int s = 0; lines[l].codes[s]; ++s) {
      const char *code = lines[l].codes[s];

      int i = code[0] - 'A';
      int j = code[1] - 'A';
      int k = code[2] - 'A';

      printf(
        "    %s (%s)\n",
        *crs[i][j][k],
        code
      );
    }
  }
}
