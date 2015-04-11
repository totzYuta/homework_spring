#include <stdio.h> 

int vsum(int *addr, int n) {
  int sum = 0;
  int i;

  // Use while loop insted of this for loop
  /* 
  for (i = 0; i < n; i++) {
    sum += *(addr+i);
  }
  */

  i = 0;
  while (i < n) {
    sum += *(addr+i);
    i++;
  }

  return sum;
}

int main(){
  int a[5] = {1,2,3,4,5};
  int sum;
  sum = vsum(a, 5);
  printf("%d", sum);
  return 0;
}
