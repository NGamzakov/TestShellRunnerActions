#include <stdio.h>
#include <stdlib.h>

void run() {
  printf("faith\n");
  char text[256];
  text[0] = '\0';
  for(size_t i = 0; i < 10; i += 1) {
    size_t a = i;
    size_t k = a + i;
    text[i] = i + 'a';
    text[i + 1] = '\0';
    // printf("%ld\n", i);
  }

  for(size_t i = 0; i < 10; i += 1) {
    if(i % 2 != 0) {
      printf("%ld\n", i);
    }
    else {
      printf("%ld\n", i);
    }
  }
}

int main() {
  run();
  size_t a = 2;
  size_t k = 3 + a;
}
