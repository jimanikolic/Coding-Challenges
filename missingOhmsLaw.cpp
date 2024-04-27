/*
Challenge #2 - Create a function that calculates the missing value of 3 
inputs using Ohm’s law. The inputs are v, r or i (aka: voltage, resistance and current).
Runtime - O(1), constant
Solution - use getline to store three tokens, use istringsteam to convert tokens to doubles.
Empty strings are stored as 0.
*/

#include <iostream>
#include <string>
#include <sstream>
#include <vector>

using namespace std;

double findMissingValue(double v, double r, double i);

int main() {
    double v = 0, r = 0, i = 0;
    string input;

    cout << "Enter Voltage (v), Resistance (r), Current (i) separated by commas: ";
    getline(cin,input);

    istringstream iss(input);
    vector<string> tokens;
    string token;
    while (getline(iss, token, ',')) {
        tokens.push_back(token);
    }

   // Check if there are exactly 3 tokens or 2 tokens with an empty third token
    if (tokens.size() != 3 && (input.back() == ',')) {
        tokens.push_back(""); // Append an empty token
    } else if (tokens.size() != 3) {
        cout << "Error: Invalid input format." << endl;
        return 1;
    }


    istringstream(tokens[0]) >> v;
    istringstream(tokens[1]) >> r;
    istringstream(tokens[2]) >> i;
    double value = findMissingValue(v, r, i);

    cout << value << endl;
}


double findMissingValue(double v, double r, double i) {
    double value = 0;
    // Ohm's Law: v = i * r
    if (v == 0) {
        cout << "v is: ";
        value = i * r;
    }

    else if (r == 0) {
        cout << "r is: ";
        value = v / i;
    }

    else if (i == 0) {
        cout << "i is: ";
        value = v / r;
    }
    return value;
}