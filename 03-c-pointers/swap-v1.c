#include <stdio.h>

int swap(int a, int b) {
  int tmp = a;
  a = b;
  b = tmp;
}

int main() {
  int x = 10;
  int y = 100;
  swap(x, y);
  printf("x=%d, y%d\n", x, y); // x is still 10 and y is still 100: the swap operated
                               // on a and b in the function swap's stack frame
}
