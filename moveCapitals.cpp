/*
Challenge #1 - Create a function that moves all capital letters to the front of a word.
Runtime - O(n^2), where n is the length of the string;
Solution - Simple bubble sort acting on ascii values
*/
#include <iostream>
#include <string>


using namespace std;

int main () {

    string myString;
    myString = "TeSt Me PlEaSe";
    // n is the total number of elemetns in the array
    int n = myString.length();

    // simple Bubble sort, ascii value will pull out capital letters
    // i is number of iterations so far
    for (int i = 0; i < n - 1; i++) {

        // after each iteration, largest element is placed at end of array,
        // so we use -i in the conditional, as we dont need to check end values again
        for (int j = 0; j < n - i -1; j++) {
            if (myString[j] > myString[j+1]) {
                char temp = myString[j];
                myString[j] = myString[j+1];
                myString[j+1] = temp;
            }
        }
    }

    cout << myString;
}

