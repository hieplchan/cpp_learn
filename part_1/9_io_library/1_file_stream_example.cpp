#include <fstream>
#include <iostream>
#include "Sales_data.h"

int main(int argc, char **argv) {
    std::cout << "IO Library File Stream example" << std::endl;
    std::ifstream input(argv[1]);
    // std::ofstream output(argv[2]);
    std::ofstream output; // another way to open file
    output.open(argv[2], std::ofstream::app | std::ofstream::out); // keep previous data

    Sales_data total;
    if (read(input, total)) {
        Sales_data trans;
        while (read(input, trans))
        {
            if (total.isbn() == trans.isbn()) {
                total.combine(trans);
            } else {
                print(output, total) << std::endl;
                total = trans;
            }
        }
        print(output, total) << std::endl;
    } else {
        std::cerr << "No data ?!" << std::endl;
    }

    input.close();
    output.close();
    
    return 0;
}