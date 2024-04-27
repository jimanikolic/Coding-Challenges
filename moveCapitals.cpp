#include <iostream>
#include <string>


using namespace std;

int main () {

    string myString;
    myString = "TeSt Me PlEaSe";

    for (int i = 0; i < myString.length(); i++) {
        cout << myString[i];
    }

}

