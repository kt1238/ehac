#include <stdio.h>
#include <string.h>

static char atbash(char source) {
  if (source >= 'a' && source <= 'z') {
    return 'z' - source + 'a'; // e.g 172(z) - 142 (b) + 141 (a) = 171 (y) ascii
  }
  if (source >= 'A' && source <= 'Z') {
    return 'Z' - source + 'A';
  }
  return source;
}

int main(int argc, char *argv[]) {
  if (argc == 1) {
    printf("syntax: %s <text>\r\n", argv[0]);
    return 1;
  }
  if (argc > 1) {
    for (size_t j = 1; j < argc; ++j) {
      for (size_t i = 0; i < strlen(argv[j]); ++i) {
        printf("%c", atbash(argv[j][i])); // %c need to tell printf to print characters
      }
      putchar(' ');
    }
    printf("\r\n");
  }
  return 0;
}
