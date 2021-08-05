#include "Sales_data.h"

using std::cout;
using std::cin;
using std::endl;
using std::cerr;

int main() {
    cout << "Sales_data class simple example" << endl;
    cout << "Size of Sales_data object: " << sizeof(Sales_data) << " bytes" << endl;

    // Testing constructor
    cout << "Constructor test" << endl;
    Sales_data test1; // default constructor
    Sales_data test2("0-201-78345-1");
    Sales_data test3("0-201-78345-2", 3, 10);
    Sales_data test4(cin);
    print(cout, test1) << endl;
    print(cout, test2) << endl;
    print(cout, test3) << endl;
    print(cout, test4) << endl;

    // test5 is a function take no argument, return type Sales_data
    // test5 is not an object of Sales_data!!!! This is a function
    Sales_data test5(); 

    cout << "Programe test" << endl;
    Sales_data total;
    if (read(cin, total)) {
        Sales_data trans;
        while (read(cin, trans))
        {
            if (total.isbn() == trans.isbn()) {
                total.combine(trans);
            } else {
                print(cout, total) << endl;
                total = trans;
            }
        }
        print(cout, total) << endl;
    } else {
        cerr << "No data ?!" << endl;
    }
    
    return 0;
}