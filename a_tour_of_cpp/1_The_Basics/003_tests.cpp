#include <iostream>
#include <vector>

using namespace std;

void do_something(const vector<int>& input)
{
    // n is initialized and scoped within if statement
    if (int n = input.size())
    {
        // noop
    }
}

void basic()
{
    cout << "Yes or no?\n";
    char answer;
    cin >> answer;

    switch(answer)
    {
        case 'y':
            cout << "Yes\n";
            break;
        case 'n':
            cout << "No\n";
            break;
        default:
            cout << "I take it as No\n";
            break;
    }
}

int main()
{
    basic();

    return 0;
}