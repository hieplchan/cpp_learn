#include <iostream>
#include <stack>

struct Node {
    int data;
    Node *link;
};
Node *head = nullptr;

void add_element_to_list_begin(int x) {
    Node *temp = new Node;
    temp->data = x;
    temp->link = head;
    head = temp;
}

void print_list() {
    Node *temp = head;
    printf("List: ");
    while (temp != nullptr) {
        printf("%d ", temp->data);
        temp = temp->link;
    }
    printf("\n");
}

void reverse_list_using_stack() {
    std::stack<Node *> temp_stack;
    Node *temp_node = head;

    while (temp_node != nullptr) {
        temp_stack.push(temp_node);
        temp_node = temp_node->link;
    }

    temp_node = temp_stack.top();
    head = temp_node;
    temp_stack.pop();
    while (!temp_stack.empty()) {
        temp_node->link = temp_stack.top();
        temp_stack.pop();
        temp_node = temp_node->link;
    }
    temp_node->link = nullptr;
}

int main() {
    add_element_to_list_begin(4);
    add_element_to_list_begin(3);
    add_element_to_list_begin(2);
    add_element_to_list_begin(1);
    print_list();

    reverse_list_using_stack();
    print_list();

    return 0;
}