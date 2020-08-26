#include <stdio.h>
#include <string.h>
#include <stdlib.h>

int
main (int argc, char *argv[]){
  int n = atoi (argv[1]);
  int height = n;
  int width = 2*n - 1;
  for (int i = 0; i < height; i++){
      int r = i;
      for (int j = 0; j < width; j++){
          if (abs(width/2 - j) <= r){
              printf("*");
          } else {
              printf(" ");
          }
      }
      printf("\n");
  }
  return 0;
}