/*
Challenge #7 - Write a function that adds two 
numbers and determines wether or not they can overflow
runtime O(1)
5/9/2024
*/
#include <stdio.h>


int uadd_ok(unsigned x, unsigned u);

int main () {

  unsigned x = 16;
  unsigned y =71234;
  int result = 0;

  result = uadd_ok(x, y);

  if (result == 1) {
    printf("all good");
  }

  else {
    printf("overflowed");
  }

  return 1;
}


int uadd_ok(unsigned x, unsigned y) {

  unsigned sum = x+y;
  return sum >= x;
} 