#include <sstream>
#include <iostream>
#include <vector>

struct PersonInfo
{
    std::string name;
    std::vector<std::string> phones;
};

bool valid(std::string num) {
    return num.size() > 5;
}

std::string format(std::string num) {
    return "+84" + num;
}

int main() {
    std::cout << "String stream example" << std::endl;

    std::vector<PersonInfo> people;
    std::string line, word;

    // istringstream often used when some work do with entire line - another work do with individual words of line
    while (std::getline(std::cin, line)) {
        PersonInfo info;
        std::istringstream record(line);
        record >> info.name;
        while (record >> word) {
            info.phones.push_back(word);
        }
        people.push_back(info);        
    }
    std::cout << "Total person: " << people.size() << std::endl;

    // ostringstream is useful when we need to build up output - reformat... - and print output after all
    for (const auto &entry : people) {
        std::ostringstream formatted, badNums;
        for (const auto &nums : entry.phones) {
            if (!valid(nums)) {
                badNums << " " << nums;
            } else {
                formatted << " " << format(nums);
            }
        }
        if (badNums.str().empty()) {
            std::cout << entry.name << " "
                      << formatted.str() << std::endl;
        } else {
            std::cerr << "input error: " << entry.name << " invalid number: " << badNums.str() << std::endl;
        }
    }

    return 0;
}