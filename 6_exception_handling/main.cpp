#include "Sales_data.h"
#include <iostream>

using std::cin; 
using std::cout; 
using std::endl;
using std::string;

int main() {

    cout << "Exception Handle" << endl;

    Sales_data data1, data2;
    double price = 0, average = 0;

    cin >> data1.bookNo >> data1.units_sold >> price;
    data1.revenue = data1.units_sold * price;

    cin >> data2.bookNo >> data2.units_sold >> price;
    data2.revenue = data2.units_sold * price;

    if (data1.bookNo == data2.bookNo) {
        unsigned count = data1.units_sold + data2.units_sold;
        if (count != 0) {
            cout << (data1.revenue + data2.revenue)/count << endl;
        } else {
            cout << "No sales" << endl;
        }
        return 0;
    } else {
        throw std::runtime_error("Please enter same ISBN");
        // cout << "Please enter same ISBN" << endl;
        return -1;
    }
}