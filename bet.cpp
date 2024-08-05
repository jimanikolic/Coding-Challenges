#include <stdio.h>
#include <cstdlib>
#include <iostream>
#include <string.h>
#include <ctime>

using namespace std;

string roulette();

void respinRoulette();

int main () {
    srand(static_cast<unsigned int>(time(0)));


    int wincount = 0;
    int losscount = 0;
    int bet = 50;
    int money = 50000;
    int range = 100;\
    int winnings = 0;

    while (winnings + money <= 500000) {
        string result = roulette();

        if (result == "black") {
            cout << " win\n";
            money -= bet;
            winnings += bet *2;
            wincount++;
        }

        if (result == "red" || result == "green") {
            cout << " loss\n";
            money -= bet;
            bet = bet * 2;
            losscount++;
        }
    }

    cout << "total " << winnings + money;

}

string roulette() {
    int num = 0;
    num = rand() % 101;
    cout << num;

    if (num ==0) {
        return "green";
    }

    if (num % 2 == 0){
        return "black";
    }

    else {
        return "red";
    }
}