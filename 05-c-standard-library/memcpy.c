# include <stdio.h>
# include <string.h>

typedef struct {
    int m1; int m2; int m3; float f1;
} mystruct;

int main() {
  int array_size = 10;
  mystruct array1[array_size];
  mystruct array2[array_size];

  for(int i=0; i<array_size; i++) { // initialise all of array1's members
    array1[i].m1 = 1;
    array1[i].m2 = 2;
    array1[i].m3 = 3;
    array1[i].f1 = 4;
  }
  
  /* Assume we want to make a copy of array1 into array2 */
  memcpy(array2, array1, array_size*sizeof(mystruct)); // easier (and faster) vs. a loop

  printf("%d %d %d %d\n", array2[0].m1, array2[1].m1, array2[2].m1, array2[3].m1);
}