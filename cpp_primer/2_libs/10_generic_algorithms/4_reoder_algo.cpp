// https://www.geeksforgeeks.org/stdunique-in-cpp/

#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

// reduce duplicate words
void elimDups(std::vector<std::string> &words) {
    // sort alphabetically so we can find duplicates
    std::sort(words.begin(), words.end());
    // reorder input, return begin iterator on duplicate
    // do not remove element, size is the same
    auto end_unique = std::unique(words.begin(), words.end());
    // algorithm can not add or remove container element
    // need to use container operation to do this
    words.erase(end_unique, words.end());
}

int main() {
    std::cout << "Start programme" << std::endl;
    
    std::vector<std::string> words = {"the", "quick", "red", "fox", "jumps", "over", "the", "slow", "red", "turtle"};

    elimDups(words);

    std::cout << "Result: ";
    for (auto iter = words.cbegin(); iter != words.cend(); ++iter) {
        std::cout << *iter << " ";
    }
    std::cout << std::endl;

    return 0;
}