#include <iostream>
#include <string>

int main() {

    std::cout << "Binary search start, please input charactor to find" << std::endl;

    std::string text("123456789abcdef");
    char search_charactor;

    std::cin >> search_charactor;
    std::cout << "Start searching charactor: " << search_charactor << std::endl;

    auto begin = text.begin();
    auto end = text.end();
    auto mid = text.begin() + (end - begin)/2;
    auto sought = begin;

    while ((mid != end) && (*mid != search_charactor)) {
        if (search_charactor < *mid) {
            end = mid;
        } else {
            begin = mid + 1;
        }
        mid = begin + (end - begin)/2;
    }

    if (*mid == search_charactor) {
        std::cout << "Find " << search_charactor << " at position: " << mid - text.begin() + 1<< std::endl; 
    } else {
        std::cout << "Can not find charactor: " << search_charactor << std::endl;
    }

    return 0;
}