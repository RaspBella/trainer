#include <stdlib.h>
#include <stdio.h>
#include "../crs.h"

struct line {
  const char *name;
  const char **codes;
};

#define LINE(NAME, ...) (struct line) { \
  .name = NAME, \
  .codes = (const char *[]){ __VA_ARGS__ } \
},

int main(void) {
  struct line lines[] = {
#include "lines.def"
  };

  printf("Lines:\n");

  for (int i = 0; i < ARRAY_LEN(lines); ++i) {
    printf("  %s:\n", lines[i].name);

    for (int j = 0; j < lines[i].stations.count; ++j) {
      printf("    %s\n", crs[lines[i].stations.xs[j]].name);
    }
  }
}
