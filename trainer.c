#include <stdlib.h>
#include <stdio.h>
#include "../crs.h"

#define ARRAY_LEN(xs) sizeof(xs) / sizeof((xs)[0])

struct array {
  int count;
  int *xs;
};

#define ARRAY(...) (struct array) { \
  .count = ARRAY_LEN(((int[]){__VA_ARGS__})), \
  .xs = (int[]){__VA_ARGS__} \
}

struct line {
  const char *name;
  struct array stations;
};

#define LINE(NAME, ...) (struct line) { \
  .name = NAME, \
  .stations = ARRAY(__VA_ARGS__) \
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
