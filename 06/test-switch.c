// test.c

#include <time.h>
#include <stdlib.h>

int main() {
  int a = 3;
  int b = 10;

  switch (a) {
    case 1:
      b = 11;
      break;
    case 2:
      b = 12;
      break;
    case 3:
      b = 13;
      break;
    default:
      b = 14;
      break;
  }
}