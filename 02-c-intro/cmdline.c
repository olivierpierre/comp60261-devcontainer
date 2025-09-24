#include <stdio.h>

int main(int argc, char **argv) { // 'char ** argv' means 'char argv[][]'
    printf("Number of command line arguments: %d\n", argc);
    for(int i = 0; i<argc; i++)
      printf("argument %d: %s\n", i, argv[i]); // no need for braces when the body of the loop
                                            // is a single line
    return 0;
}

