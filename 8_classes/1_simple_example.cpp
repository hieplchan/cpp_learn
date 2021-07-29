#include "Sales_data.h"

using std::cout;
using std::cin;
using std::endl;
using std::cerr;

int main() {
    cout << "Sales_data class simple example" << endl;
    cout << "Size of Sales_data object: " << sizeof(Sales_data) << " bytes" << endl;

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