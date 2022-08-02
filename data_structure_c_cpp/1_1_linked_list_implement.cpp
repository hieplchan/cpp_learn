#include <iostream>
#include <string>

struct Node {
    int data;
    Node *next;
};

void log(std::string message) {
    std::cout << "__LOG__ " << message << std::endl;
}

void insert_end(Node **pointerToHead, int in_data) {
    // Create node
    Node *temp_node = (Node *) malloc(sizeof(Node));
    temp_node->data = in_data;
    temp_node->next = nullptr;

    // Add node to list
    if (*pointerToHead != nullptr) {
        Node *end_node = *pointerToHead;
        // Find end element
        while (end_node->next !=nullptr) {
            end_node = end_node->next;
        }
        end_node->next = temp_node;
    } else {
        *pointerToHead = temp_node;
    }
}

void insert_begin(Node **pointerToHead, int in_data) {
    // Create node
    Node *temp_node = (Node *) malloc(sizeof(Node));
    temp_node->data = in_data;
    temp_node->next = *pointerToHead;
    *pointerToHead = temp_node;
}

void insert_at_position(Node **pointerToHead, int in_data, size_t position) {
    // Create node
    Node *new_node = (Node *) malloc(sizeof(Node));
    new_node->data = in_data;
    new_node->next = nullptr;

    if (position == 1) {
        new_node->next = *pointerToHead;
        *pointerToHead = new_node;
        return;
    }

    Node *temp = *pointerToHead;
    for (int i = 0; i < position - 2; i++) {
        temp = temp->next;
        if (temp == nullptr) {
            std::cout << "invalid position" << std::endl;
            return;
        }
    }
    new_node->next = temp->next;
    temp->next = new_node;
}

void delete_at_postion(Node **pointerToHead, size_t position) {
    if (*pointerToHead == nullptr) {
        log("List is empty, can not delete");
        return;
    }

    Node *temp = *pointerToHead;

    // Delete first element in list
    if (position == 1) {
        *pointerToHead = (temp)->next;
        free(temp);
        return;
    }

    for (int i = 0; i < position-2; i++) {
        temp = temp->next;
        if (temp == nullptr) {
            log("Invalid delete position");
            return;
        }
    }
    Node *temp2 = temp->next;
    if(temp2 == nullptr) {
        log("Invalid delete position");
        return;
    }

    temp->next = temp2->next;
    free(temp2);
}

void reverse_linked_list(Node **pointerToHead) {
    Node *pCurrent, *pPrevious, *pNext;
    pCurrent = *pointerToHead;
    pPrevious = nullptr;

    while (pCurrent != nullptr) {
        pNext = pCurrent->next;
        pCurrent->next = pPrevious;
        pPrevious = pCurrent;
        pCurrent = pNext;
    }
    *pointerToHead = pPrevious;
}

void reverse_linked_list_recursion(Node **pointerToHead, Node *node) {
    if (*pointerToHead == nullptr) {
        return;
    }

    if (node->next == nullptr) {
        *pointerToHead = node;
        return;
    }
    reverse_linked_list_recursion(pointerToHead, node->next);
    node->next->next = node;
    node->next = nullptr;
}

void print(Node *head) {
    Node *temp_node = head;
    std::cout << "List is: ";
    while (temp_node != nullptr) {
        std::cout << " " << temp_node->data;
        temp_node = temp_node->next;
    }
    std::cout << std::endl;
}

void print_recursion(Node *node) {
    if (node != nullptr) {
        std::cout << std::to_string(node->data) << " ";
        print_recursion(node->next);
    } else {
        return;
    }
}

void print_reverse_recursion(Node *node) {
    if (node != nullptr) {
        print_recursion(node->next);
        std::cout << std::to_string(node->data) << " ";
    } else {
        return;
    }
}

int main() {
    Node *A = nullptr;

    size_t list_size = 0;
    std::cout << "How many element you want in list?" << std::endl;
    std::cin >> list_size;
    std::cout << "List size: " << list_size << std::endl;

    for (size_t i = 0; i < list_size; i++) {
        std::cout << "Please enter data" << std::endl;
        int in_data;
        std::cin >> in_data;
        // insert_end(&A, in_data);
        insert_begin(&A, in_data);
        print(A);
    }

    // // Insert at position, begin position is 1
    // size_t insert_position = 0;
    // int insert_data = 0;
    // std::cout << "Please enter insert position" << std::endl;
    // std::cin >> insert_position;
    // std::cout << "Please enter insert data" << std::endl;
    // std::cin >> insert_data;
    // insert_at_position(&A, insert_data, insert_position);
    // print(A);

    // // Delete at position, begin position is 1
    // size_t delete_position = 0;
    // std::cout << "Please enter delete position" << std::endl;
    // std::cin >> delete_position;
    // delete_at_postion(&A, delete_position);
    // print(A);

    // // Reverse a linked list
    // reverse_linked_list(&A);
    // print(A);

    // // Print using recursion
    // log("Print using recursion");
    // print_recursion(A);

    // // Print reverse using recursion
    // log("Print reverse using recursion");
    // print_reverse_recursion(A);

    // Reverse list using recursion
    reverse_linked_list_recursion(&A, A);
    print(A);

    return 0;
}