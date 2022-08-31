#include <iostream>
#include <vector>
#include <string>
#include <numeric>

int main() {
    std::cout << "Start programme" << std::endl;

    // Sample data
    std::vector<int> test_vector = {1, 2, 3, 4, 5, 6, 7};
    std::vector<int> test_vector_1 = {1, 2, 3, 4, 5, 6, 99};
    std::vector<int> test_vector_2 = {1, 2, 3, 4, 5, 6};
    std::vector<std::string> test_vector_of_string = {"hello", "world"};
    std::vector<std::string> test_vector_of_string_1 = {"hello", "people"};
    
    // Accumulate
    std::cout << "accumulate result 1: " << std::accumulate(test_vector.cbegin(), test_vector.cend(), 0) << std::endl;
    std::cout << "accumulate result 2: " << std::accumulate(test_vector_of_string.cbegin(), test_vector_of_string.cend(), std::string("")) << std::endl;

    // Equal
    std::cout << "equal result 1: " << std::equal(test_vector.cbegin(), test_vector.cend(), test_vector_1.cbegin()) << std::endl;
    std::cout << "equal result 2: " << std::equal(test_vector.cbegin(), test_vector.cend(), test_vector.cbegin()) << std::endl;
    std::cout << "equal result 3: " << std::equal(test_vector_of_string.cbegin(), test_vector_of_string.cend(), test_vector_of_string_1.cbegin()) << std::endl;
    std::cout << "equal result 4: " << std::equal(test_vector_of_string.cbegin(), test_vector_of_string.cend(), test_vector_of_string.cbegin()) << std::endl;

    // Size error ????
    std::cout << "equal result 5: " << std::equal(test_vector.cbegin(), test_vector.cend(), test_vector_2.cbegin()) << std::endl;

    return 0;
}