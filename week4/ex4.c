#include <stdio.h>
#include <string.h>
#include <stdlib.h>
void swap(int *n1, int *n2){
    int temp;
    temp = *n1;
    *n1 = *n2;
    *n2 = temp;
}

int main (){
  int a;
  int b;
  scanf("%d", &a);
  scanf("%d", &b);
  swap(&a, &b);
  printf("%d", a);
  printf(" ");
  printf("%d", b);
  return 0;
}