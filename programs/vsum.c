#include <stdio.h> 

int vsum(int *addr, int n) {
  int sum = 0;
  int i;

  i = 0;
_L1:
  if (i >= n) goto _L2;
  sum += *(addr+i);
  i++;
  goto _L1;
_L2:
  return sum;
}

int main(){
  int a[5] = {1,2,3,4,5};
  int sum;
  sum = vsum(a, 5);
  printf("%d", sum);
  return 0;
}
