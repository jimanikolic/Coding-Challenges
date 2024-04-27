#include <iostream>
#include <string>


using namespace std;

int main () {

    string myString;
    myString = "TeSt Me PlEaSe";

    int n = myString.length();

    for (int i = 0; i < n - 1; i++) {
        for (int j = 0; j < n -1; j++) {
            if (myString[j] > myString[j+1]) {
                char temp = myString[j];
                myString[j] = myString[j+1];
                myString[j+1] = temp;
            }
        }
    }
    
    cout << myString;
}

