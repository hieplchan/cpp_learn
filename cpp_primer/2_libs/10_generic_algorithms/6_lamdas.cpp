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
    // std::stable_sort(words.begin(), words.end(), isShorter);

    // using lamdas instead of isShorter
    std::stable_sort(words.begin(), words.end(),
                    [](const std::string &a, const std::string &b) 
                        {return a.size() < b.size();});

    std::cout << "result: " << std::endl;
    for (auto iter = words.cbegin(); iter != words.cend(); ++iter) {
        std::cout << *iter << " ";
    }
    std::cout << std::endl;

    // lamdas captured list (can use local variables)
    int min_size = 4;
    auto wc = std::find_if(words.begin(), words.end(), 
                                [min_size](const std::string &a)
                                { return a.size() >= min_size; });
    std::cout << "First words size > " << min_size << " is: " << *wc << std::endl;

    return 0;
}