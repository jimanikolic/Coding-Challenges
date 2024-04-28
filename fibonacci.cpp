/*
Challenge #5 - Write a function that takes an integer n 
as input and returns the nth Fibonacci number. The 
Fibonacci sequence is defined as follows: the first 
two numbers in the sequence are 0 and 1, and each 
subsequent number is the sum of the two preceding ones.
So the sequence goes: 0, 1, 1, 2, 3, 5, 8, 13, 21, and so on.
Runtime - O(), constant
*/

#include <iostream>

using namespace std;

int fibonacci(int n);


int main() {
   int x, i=0;
   cout << "Enter the number of terms of series : ";
   cin >> x;
   cout << "\nFibonnaci Series: ";
   while(i < x) {
      cout << " " << fibonacci(i);
      i++;
   }
   return 0;
}

int fibonacci(int n) {
  if(n <= 1) {
    return n;
  }

  else {
    return (fibonacci(n-1) + fibonacci(n-2));
    }

}