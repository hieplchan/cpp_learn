#include <iostream>
#include <vector>

int main() {
    std::cout << "Start program" << std::endl;

    // Create sample vector
    std::vector<int> test_vector;
    // Add some test element to vector
    for (size_t i = 0; i < 24; i++) {
        test_vector.push_back(i);
    }

    // Check memory
    std::cout << "Vector size: " << test_vector.size() << std::endl;
    // Maybe some more memory is reserved
    std::cout << "Vector capacity: " << test_vector.capacity() << std::endl;

    // Shrink to reduce memory, depend on lib implementation - no guarentee
    test_vector.shrink_to_fit();
    std::cout << "Vector size after shrink: " << test_vector.size() << std::endl;
    std::cout << "Vector capacity after shrink: " << test_vector.capacity() << std::endl;

    // Reserve more memory
    test_vector.reserve(50);
    std::cout << "Vector size after reserve: " << test_vector.size() << std::endl;
    std::cout << "Vector capacity after reserve: " << test_vector.capacity() << std::endl;

    return 0;
}