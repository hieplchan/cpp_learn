#include <iostream>
#include <vector>
#include <string>
#include <algorithm>

void elimDups(std::vector<std::string> &words) {
    std::sort(words.begin(), words.end());
    auto ret = std::unique(words.begin(), words.end());
    words.erase(ret, words.end());
}

bool isShorter(const std::string &s1, const std::string &s2) {
    return s1.size() < s2.size();
}

int main() {
    std::vector<std::string> words = {"the", "quick", "red", "fox", "jumps", "over", "the", "slow", "red", "turtle"};

    // put words in alphabetically order and remove duplicate
    elimDups(words);
    // std::sort(words.begin(), words.end(), isShorter);
    // short by lenght but maintain alphabetically order
    std::stable_sort(words.begin(), words.end(), isShorter);

    std::cout << "result: " << std::endl;
    for (auto iter = words.cbegin(); iter != words.cend(); ++iter) {
        std::cout << *iter << " ";
    }
    std::cout << std::endl;

    return 0;
}