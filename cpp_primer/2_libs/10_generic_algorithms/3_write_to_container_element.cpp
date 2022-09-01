#include <iostream>
#include <vector>
#include <list>
#include <algorithm>
#include <iterator>

int main() {
    std::vector<int> test_vector = {1, 2, 3, 4, 5, 6};
    std::list<int> test_list;
    int a1[] = {1, 2, 3, 4, 5};
    int a2[sizeof(a1)/sizeof(*a1)];
    
    // Fill
    std::fill(test_vector.begin(), test_vector.begin() + test_vector.size()/2, 99);
    std::cout << "fill result: ";
    for (auto iter = test_vector.cbegin(); iter != test_vector.cend(); ++iter) {
        std::cout << *iter << " ";
    }
    std::cout << std::endl;

    // fill_n 
    // when you not know what is end iterator, make sure we have n element after dest iter
    std::cout << "fill_n result: ";
    std::fill_n(std::ostream_iterator<int>(std::cout), 5, 10);
    std::cout << std::endl;

    // Undefined behavior, do not do this
    std::cout << "fill_n result on empty container: ";
    std::fill_n(test_list.begin(), 5, 1);
    for (auto iter = test_list.cbegin(); iter != test_list.cend(); ++iter) {
        std::cout << *iter << " ";
    }
    std::cout << std::endl;

    // Insert iterator - add element to container
    // safe to do this compare to above method
    std::fill_n(std::back_inserter(test_list), 5, 1);
    std::cout << "Insert result on empty container: ";
    for (auto it = test_list.cbegin(); it != test_list.cend(); ++it) {
        std::cout << *it << " ";
    }
    std::cout << std::endl;

    // Copy
    auto ret = std::copy(std::begin(a1), std::end(a1), a2);
    std::cout << "Copy result: ";
    for (auto iter = std::begin(a2); iter != std::end(a2); ++iter) {
        std::cout << *iter << " ";
    }
    std::cout << std::endl;

    // Replace
    std::replace(test_vector.begin(), test_vector.end(), 99, 8);
    std::cout << "replace result: ";
    for (auto iter = test_vector.cbegin(); iter != test_vector.cend(); ++iter) {
        std::cout << *iter << " ";
    }
    std::cout << std::endl;
    // replace and copy
    std::vector<int> test_vector_result;
    std::replace_copy(test_vector.cbegin(), test_vector.cend(), std::back_inserter(test_vector_result), 8, 7);
    std::cout << "replace and copy result: ";
    for (auto iter = test_vector_result.cbegin(); iter != test_vector_result.cend(); ++iter) {
        std::cout << *iter << " ";
    }
    std::cout << std::endl;
    return 0;
}