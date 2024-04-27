/*
Challenge #3 - Write a program that dynamically allocates 
memory for an array of integers, prompts the user to input the 
elements of the array, reverses the array in-place using pointers, 
and then deallocates the memory. Ensure that the program handles 
memory allocation failure gracefully.
Runtime - O(1), constant
*/


#include <iostream>
#include <string>
#include <limits>

using namespace std;

int* createArray(int size);
void viewArray(int size, int* arr);
int* reverseArray(int size, int* arr);

int main() {
  int size = 0;
  cout << "How many elements do you want to be in the array? (Array needs to be an int larger than 0) " << endl;
  while(!(cin >> size) || size<=0){
    cout << "How many elements do you want to be in the array? (Array needs to be an int larger than 0) " << endl;
    cin.clear();
    cin.ignore();
    
  }

  int* arr = createArray(size);
  cout << "Origional Array: ";
  viewArray(size, arr);

  cout << "Reversed Array: ";
  int* revArr= reverseArray(size,arr);
  viewArray(size, revArr);

  delete[] arr;
  return 0;
  
}

int* createArray(int size) {
  // pointer arr = dynamically allocates memory for an array of n ints on heap. 

  // crazy bug I encountered: using int(size) allocates a single integer initialized with value size
  // using int[size], allocates an array of integers, this worked up until values n = 8 as that is the size of an integer
  // have to use [] for n > 7
  int *arr = new (nothrow) int[size];

  if (arr == nullptr) {
        cerr << "Memory allocation failed. Exiting program." << endl;
        exit(EXIT_FAILURE); // Terminate the program gracefully
    }

  for (int i = 0; i < size; i++) {

    int x = 0;
    cout << "enter item #" << i << endl;
    while(!(cin >> x)){
      cout << "item has to be an int value " << endl;
      cin.clear();
      cin.ignore();
    }

    arr[i] = x;
  }

  // returns a pointer to the first element of the array
  return arr;

}

void viewArray(int size, int* arr) {

  for (int i = 0; i < size; i++) {
    cout << arr[i] << " ";
  }

  cout << endl;
}

int* reverseArray(int size, int* arr){
  int* start = arr;
  int* end = arr + size -1;

  while (start < end) {

    // Reverse the array via bitwise XOR, use pointers to retieve values, meaning no extra memory is used.
    *start ^= *end;
    *end ^= *start;
    *start ^= *end;

    start++;
    end--;
  }

  return arr;

}
