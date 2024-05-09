/*
Challenge #7 - Write a function that adds two 
numbers and determines wether or not they can overflow
runtime O(1)
5/9/2024
*/


#include <stdio.h>
int uadd_ok(unsigned int x, unsigned int u);

int main () {

  unsigned int x = 18446744073709551614;
  unsigned int y = 1;
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


int uadd_ok(unsigned int x, unsigned int y) {

  unsigned sum = x+y;
  return sum >= x;
} 