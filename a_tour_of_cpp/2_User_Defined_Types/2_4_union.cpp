#include <string>
#include <iostream>
#include <variant>

using namespace std;

struct Node { 
    Node* nextNode;
    int value;
};

enum EntryType {ptr, num};

// wasted memory of p, i
struct EntryOld {
    string name;
    EntryType t;
    Node* p;    // using if t==ptr
    int i;      // using if t==num
};

void TestOld(EntryOld& entry)
{
    if (entry.t == ptr)
        cout << entry.p->value;
    else if (entry.t == num)
        cout << entry.i;
}

union EntryValue {
    Node* p;
    int i;
};

struct EntryNew
{
    string name;
    EntryType t;
    EntryValue v;
};

void TestNew(EntryNew& entry)
{
    if (entry.t == num)
        cout << entry.v.i;
    else if (entry.t == ptr)
        cout << entry.v.p->value;
}

struct EntryVariant
{
    string name;
    variant<Node*, int> v;
};

void TestVariant(EntryVariant& entry)
{
    if (holds_alternative<int>(entry.v))
        cout << get<int>(entry.v);
    else if (holds_alternative<Node*>(entry.v))
        cout << get<Node*>(entry.v)->value;
}





