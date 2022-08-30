#include <iostream>
#include <stack>
#include <vector>
#include <queue>

int main() {
    std::stack<int> test_stack;
    std::vector<int> test_vector;
    std::queue<int> test_queue;

    // Add some test element
    for (size_t i = 0; i < 10; i++) {
        test_stack.push(i);
        test_vector.push_back(i);
        test_queue.push(i);
    }

    std::cout << "Test stack " << std::endl;
    while (!test_stack.empty()) {
        std::cout << test_stack.top() << " ";
        test_stack.pop();
    }
    std::cout << std::endl;

    // Stack build on top of vector
    std::stack<int, std::vector<int>> test_stack_vector(test_vector);
    while (!test_stack_vector.empty()) {
        std::cout << test_stack_vector.top() << " ";
        test_stack_vector.pop();
    }
    std::cout << std::endl;

    std::cout << "Test queue " << std::endl;
    while (!test_queue.empty()) {
        std::cout << test_queue.front() << " ";
        test_queue.pop();
    }
    std::cout << std::endl;

    return 0;
}