/*
 * 春課題 I : スタック配列版
 */

#include <stdio.h>
#include <stdlib.h>

#define STACKMAX 50

int stack_1[STACKMAX];
int stack_2[STACKMAX];

int counter_1 = 0;
int counter_2 = 0;

void
push(int stackid, int n) {
  if (stackid == 1) {
    if (counter_1 == STACKMAX) {
      printf("Stack_1 overflow.\n");
    } else {
      stack_1[counter_1++] = n;
    }
  } else if (stackid == 2) {
    if (counter_2 == STACKMAX) {
      printf("Stack_2 overflow.\n");
    } else {
      stack_2[counter_2++] = n;   // (1)
    }
  }
}

int 
pop(int stackid) {
  if (stackid == 1) {
    if (counter_1 < 1) {
      printf("Stack_1 underflow.\n");
      exit(1);
    } else {
      return stack_1[--counter_1];
    }
  } else if (stackid == 2) {
    if (counter_2 < 1) {
      printf("Stack_2 underflow.\n");
      exit(1);
    } else {
      return stack_2[--counter_2];  // (2)
    }
  }
}

int
main(int argc, char *argv[]) {
  push(1,1);
  push(2,2);

  push(1,3);
  push(2,4);

  push(1,5);

  printf("Pop from Stack1: %d\n", pop(1));
  printf("Pop from Stack1: %d\n", pop(1));
  printf("Pop from Stack1: %d\n", pop(1));

  printf("Pop from Stack2: %d\n", pop(2));
  printf("Pop from Stack2: %d\n", pop(2));
  printf("Pop from Stack2: %d\n", pop(2));

}
