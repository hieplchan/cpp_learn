#include <iostream>
#include "Account.h"

using std::cout;
using std::endl;

int main() {
    cout << "Static member of class example" << endl;

    Account ac1; // static member is not part of object -> not initialized by constructor
    Account *ac2 = &ac1;
    Account ac3;
    
    double r;
    r = ac1.rate();
    r = ac2->rate();
    r = Account::rate(); // direct access static member using scope operator

    // Test
    cout << ac1.rate() << " " << ac3.rate() << endl;
    Account::rate(10);
    cout << ac1.rate() << " " << ac3.rate() << endl;

    return 0;
}