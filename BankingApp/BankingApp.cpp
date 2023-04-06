#include <iostream>
#include "CompoundInterest.h"

using namespace std;

/**
 * @brief This program is a simple implementation of a Compound interest calculator
 * Author: William Feliciano
 * Date: 03/30/2023
 *
 * @return int
 */
int main() {
    int exit = 0;
    CompoundInterest ci;

    while (exit != -1) {
        cout << "Welcome to the compound interest calculator" << endl;
        cout << endl << endl;

        ci.DisplayMenu();
        ci.DisplayReports();

        cout << "Enter -1 if you want to quit, enter 1 to continue and test another calculation" << endl;
        cin >> exit;

        while (cin.fail()) {
            cin.clear();
            cin.ignore(10000, '\n');
            cout << "Invalid input. \nPlease enter -1 to exit any other number to continue";
            cin >> exit;
        }


    }
    cout << "Thanks for using the compound interest calculator" << endl;
    return 0;
}
