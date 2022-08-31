#include <iostream>
#include <vector>
#include <string>
#include <array>
#include <algorithm>

int main() {
    std::cout << "Start programme" << std::endl;

    // Create some test containers
    std::array<int, 7> test_array = {1, 2, 3, 4, 5, 6, 7};
    std::vector<int> test_vector(std::cbegin(test_array), std::cend(test_array));
    std::vector<std::string> test_vector_of_string = {"hello", "world"};
    
    // Find
    auto result1 = std::find(test_array.cbegin(), test_array.cend(), 4);
    // auto result1 = std::find(test_array.cbegin(), test_array.cend(), 10);
    if (result1 != test_array.cend()) {
        std::cout << "test_array found value at position: " << result1 - test_array.cbegin() << std::endl;
    } else {
        std::cout << "test_array can not found value" << std::endl;
    }

    auto result2 = std::find(test_vector.cbegin(), test_vector.cend(), 4);
    // auto result2 = std::find(test_vector.cbegin(), test_vector.cend(), 10);
    if (result2 != test_vector.cend()) {
        std::cout << "test_vector found value at position: " << result2 - test_vector.cbegin() << std::endl;
    } else {
        std::cout << "test_vector can not found value" << std::endl;
    }

    auto result3 = std::find(test_vector_of_string.cbegin(), test_vector_of_string.cend(), std::string("world"));
    // auto result3 = std::find(test_vector_of_string.cbegin(), test_vector_of_string.cend(), std::string("ok"));
    if (result3 != test_vector_of_string.cend()) {
        std::cout << "test_vector_of_string found value at position: " << result3 - test_vector_of_string.cbegin() << std::endl;
    } else {
        std::cout << "test_vector_of_string can not found value" << std::endl;
    }

    return 0;
}
