#include "Sales_item.h"

int main() {

    Sales_item totalBook;

    if (std::cin >> totalBook) {

        Sales_item currBook;

        while (std::cin >> currBook) {
            if (totalBook.isbn() == currBook.isbn()) {
                totalBook += currBook;
            } else {
                std::cout << totalBook << std::endl;    
                totalBook = currBook;
            }            
        }
        
        std::cout << totalBook << std::endl;
    } else {
        std::cerr << "Input Error" << std::endl;
    }

    std::cout << "Size of Sales_item: " << sizeof(Sales_item) << std::endl;

    return 0;
}