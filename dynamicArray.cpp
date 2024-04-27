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
  int *arr = new int(size);

  for (int i = 0; i < size; i++) {
    cout << "enter item #" << i << endl;
    cin >> arr[i];
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
  for(int i = 0; i < size; i++){
    int* j = &arr[i];
    arr[i] = arr[size-i-1];
    arr[size-i-1] = *j;
  }

  return arr;

}
