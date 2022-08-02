// Visualization tool: https://www.cs.usfca.edu/~galles/visualization/BST.html

#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <limits.h>

int max(int a, int b) {
    return a >= b ? a : b;
}

struct BstNode {
    int data;
    struct BstNode* left;
    struct BstNode* right;
};


/* VERY SIMPLE QUEUE IMPLEMENT USING ARRAY */

#define ARRAY_MAX_SIZE 10
struct BstNode* queue_array[ARRAY_MAX_SIZE] = { NULL };
int front = -1, rear = -1;

void PrintQueueArray() {
    printf("PrintQueueArray: ");
    for (int i = 0; i < ARRAY_MAX_SIZE; i++) {
        printf(" %p", queue_array[i]);
    }
    printf("\n");
}

void Enqueue(struct BstNode* data) {
    if (front == ARRAY_MAX_SIZE - 1) {
        printf("Enqueue Error: Array is full\n");
    } else {
        front++;
        queue_array[front] = data;
        if (rear == -1) {
            rear = 0;
        }
    }
}

void Dequeue() {
    if (rear == -1) {
        printf("Dequeue Error: Empty queue");
    } else if (front == rear) {
        queue_array[rear] = NULL;
        front = rear = -1;
    } else {
        queue_array[rear] = NULL;
        rear++;
    }
}

bool IsQueueEmpty() {
    return rear == -1 ? true : false;
}

struct BstNode* Front() {
    if (rear == -1) {
        printf("Front Error: Empty queue\n");
        return NULL;
    } else {
        return queue_array[rear];
    }
}

/* QUEUE IMPLEMENT */

/* BINARY SEARCH TREE IMPLEMENT */

struct BstNode* GetNewNode(int data) {
    struct BstNode* node = (struct BstNode*) malloc(sizeof(struct BstNode));
    node->data = data;
    node->left = node->right = NULL;
    return node;
}

struct BstNode* Insert(struct BstNode* root, int data) {
    if (root == NULL) {
        // Binary search tree not have any element yet
        // printf("Insert %d to current node\n", data);
        root = GetNewNode(data);
    } else if (data <= root->data) {
        // Insert to left side
        // printf("Move to left side\n");
        root->left = Insert(root->left, data);
    } else {
        // Insert to right side
        // printf("Move to right side\n");
        root->right = Insert(root->right, data);
    }

    return root;
}

bool Search(struct BstNode* root, int value) {
    if (root == NULL) {
        // Tree not have any element
        return false;
    } else if (value == root->data) {
        return true;
    } else if (value < root->data) {
        // Search on left side
        return Search(root->left, value); 
    } else {
        // Search on right side
        return Search(root->right, value);
    }
}

struct BstNode* FindMin(struct BstNode* root) {
    if (root == NULL) {
        printf("BST do not have any element\n");
        return NULL;
    } else if (root->left == NULL) {
        // Founded min
        return root;
    } else {
        // Continue to search on left side
        return FindMin(root->left);
    }
}

struct BstNode* FindMax(struct BstNode* root) {
    if (root == NULL) {
        printf("BST do not have any element\n");
        return NULL;
    } else if (root->right == NULL) {
        // Founded max
        return root;
    } else {
        // Continue to search on right side
        return FindMax(root->right);
    }
}

// Height = max edge count from root node to leaf node
// FindHeight(leaf node) = 0
int FindHeight(struct BstNode* root) {
    if (root == NULL) {
        return -1; // Balance to make sure FindHeight(leaf node) = 0
    } else {
        return max(FindHeight(root->left), FindHeight(root->right)) + 1;
    }
}

void LevelOrderTraverse(struct BstNode* root) {
    if (root == NULL) {
        printf("LevelOrderTraverse Error: tree is empty\n");
    } else {
        // First process root node
        printf("%d ", root->data);
        if (root->left != NULL) Enqueue(root->left);
        if (root->right != NULL) Enqueue(root->right);
        
        // Continue process another node
        while (!IsQueueEmpty())
        {
            struct BstNode* current_node = Front();
            Dequeue();

            printf("%d ", current_node->data);
            if (current_node->left != NULL) Enqueue(current_node->left);
            if (current_node->right != NULL) Enqueue(current_node->right);
        }
    }
}

// PreOrder: Root -> Left Sub-tree -> Right Sub-tree
void PreOrderTraverse(struct BstNode* root) {
    if (root == NULL) return; 
    printf("%d ", root->data);
    PreOrderTraverse(root->left);
    PreOrderTraverse(root->right);
}

// InOrder: Left Sub-tree -> Root -> Right Sub-tree: Increasing
void InOrderTraverse(struct BstNode* root) {
    if (root == NULL) return; 
    InOrderTraverse(root->left);
    printf("%d ", root->data);
    InOrderTraverse(root->right);
}

// PostOrder: Left Sub-tree -> Right Sub-tree -> Root 
void PostOrderTraverse(struct BstNode* root) {
    if (root == NULL) return; 
    PostOrderTraverse(root->left);
    PostOrderTraverse(root->right);
    printf("%d ", root->data);
}

bool IsBstNodeInRange(struct BstNode* root, int min, int max) {
    if (root == NULL) {
        return true;
    } else if (root->data > min 
                && root->data < max 
                && IsBstNodeInRange(root->left, min, root->data)
                && IsBstNodeInRange(root->right, root->data, max)) {
        return true;
    } else {
        return false;
    }
}

bool IsBinarySearchTree(struct BstNode* root) {
    return IsBstNodeInRange(root, INT_MIN, INT_MAX);
}

struct BstNode* Delete(struct BstNode* root, int data) {
    if (root == NULL) {
        return root;
    } else if (data < root->data) {
        root->left = Delete(root->left, data);
    } else if (data > root->data) {
        root->right = Delete(root->right, data);
    } else {
        if (root->left == NULL && root->right == NULL) {
            // Case 1: No child
            free(root);
            root = NULL;
        } else if (root->left == NULL) {
            // Case 2: 1 child
            struct BstNode* temp = root;
            root = root->right;
            free(temp);
        } else if (root->right == NULL) {
            // Case 2: 1 child
            struct BstNode* temp = root;
            root = root->left;
            free(temp);
        } else {
            // Case 3: 2 child
            struct BstNode* temp = FindMax(root->left);
            root->data = temp->data;
            root->left = Delete(root->left, temp->data);
        }
    }
    return root;
}

struct BstNode* Find(struct BstNode* root, int data) {
    if (root == NULL) {
        // Can not find node
        return NULL;
    } else if (data < root->data) {
        // Continue find on left-subtree
        return Find(root->left, data);
    } else if (data > root->data) {
        // Continue find on right-subtree
        return Find(root->right, data);
    } else {
        // Founded node
        return root;
    }
}

// Find in-order successor of Binary search tree
struct BstNode* GetInorderSuccessor(struct BstNode* root, int data) {
    // First is to find node
    struct BstNode* current = Find(root, data);
    if (current == NULL) return NULL; // Can not find the node
    if (current->right != NULL) { // Case 1: Have right subtree, need to find minimum node of right subtree
        return FindMin(current->right);
    } else { // Case 2: Not have right subtree, need to find deepest node for which current node is in left 
        struct BstNode *successor = NULL, *ancessor = root;
        while (ancessor != current) {
            if (current->data < ancessor->data) {
                successor = ancessor;
                ancessor = ancessor->left;
            } else {
                ancessor = ancessor->right;
            }
        }
        return successor;
    }
}



/* BINARY SEARCH TREE IMPLEMENT */



int main() {
    printf("------------------------Binary search tree implementation\n");

    struct BstNode* pBstRoot = NULL;

    // Insert value to tree
    pBstRoot = Insert(pBstRoot, 15);
    pBstRoot = Insert(pBstRoot, 10);
    pBstRoot = Insert(pBstRoot, 20);
    pBstRoot = Insert(pBstRoot, 25);
    pBstRoot = Insert(pBstRoot, 8);
    pBstRoot = Insert(pBstRoot, 12);
    pBstRoot = Insert(pBstRoot, 17);
    pBstRoot = Insert(pBstRoot, 18);
    pBstRoot = Insert(pBstRoot, 19);
    pBstRoot = Insert(pBstRoot, 14);
    pBstRoot = Insert(pBstRoot, 16);

    // printf("Queue Testing\n");
    // Enqueue(pBstRoot);
    // Enqueue(pBstRoot);
    // Enqueue(pBstRoot);
    // Enqueue(pBstRoot);
    // PrintQueueArray();

    // printf("Front %p ", Front());
    // Dequeue();
    // printf("%p ", Front());
    // Dequeue();
    // printf("%p ", Front());
    // Dequeue();
    // printf("%p \n", Front());
    // Dequeue();

    printf("------------------------Traversal\n");

    // Level traverse of binary search tree
    printf("LevelOrderTraverse: ");
    LevelOrderTraverse(pBstRoot);
    printf("\n");

    // PreOrder traverse of binary search tree
    printf("PreOrderTraverse: ");
    PreOrderTraverse(pBstRoot);
    printf("\n");

    // InOrder traverse of binary search tree
    printf("InOrderTraverse: ");
    InOrderTraverse(pBstRoot);
    printf("\n");

    // PostOrder traverse of binary search tree
    printf("PostOrderTraverse: ");
    PostOrderTraverse(pBstRoot);
    printf("\n");

    printf("------------------------Utils\n");

    // Check to see if this binary tree is binary search tree or not
    printf("Check to see if binary search tree or not: %d\n", IsBinarySearchTree(pBstRoot));

    // Find Max, Min, Height of binary search tree
    printf("BST Min value: %d\n", FindMin(pBstRoot)->data);
    printf("BST Max value: %d\n", FindMax(pBstRoot)->data);
    printf("BST Height: %d\n", FindHeight(pBstRoot));
    printf("BST Inorder Sucessor of %d is: %d\n", 18, GetInorderSuccessor(pBstRoot, 18)->data);

    // Delete Node
    printf("------------------------Delete\n");
    pBstRoot = Delete(pBstRoot, 20);
    LevelOrderTraverse(pBstRoot);
    printf("\n");
    pBstRoot = Delete(pBstRoot, 12);
    LevelOrderTraverse(pBstRoot);
    printf("\n");   
    pBstRoot = Delete(pBstRoot, 25);
    LevelOrderTraverse(pBstRoot);
    printf("\n");

    // Search to see if value is exist or not
    printf("------------------------Search\n");
    int search_value = 0;
    printf("Enter value to search: ");
    scanf("%d", &search_value);

    if (Search(pBstRoot, search_value)) {
        printf("Founded %d in tree\n", search_value);
    } else {
        printf("Can not find %d in tree\n", search_value);
    }

    return 0;
}