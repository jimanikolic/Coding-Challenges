/*
Challenge #4 - Write a program that prints the numbers from 1 to 100, 
but for multiples of three print “Fizz” instead of the number 
and for multiples of five print “Buzz”. 
Runtime - O(1), constant
*/

#include <iostream>

using namespace std;

int main() {

  int n = 100;


  for(int i = 1; i <= n; i++) {

    if ((i % 3 ==0) && (i % 5==0)) {
        cout << "fizzbuzz" << endl;
    }

    else if((i % 3) == 0) {
        cout << "fizz" << endl;
    }

    else if ((i % 5) == 0) {
        cout << "buzz" << endl;
    }

    else {
    cout << i << endl;
    }
  }

}