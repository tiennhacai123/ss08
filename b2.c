#include <stdio.h>
#include <stdlib.h>

// Cấu trúc một nút trong cây
typedef struct Node {
    int data;
    struct Node* left;
    struct Node* right;
} Node;

Node* createNode(int data) {
    Node* newNode = (Node*)malloc(sizeof(Node));
    newNode->data = data;
    newNode->left = NULL;
    newNode->right = NULL;
    return newNode;
}

void insert(Node** root, int data) {
    if (*root == NULL) {
        *root = createNode(data);
        return;
    }

    if (data < (*root)->data) {
        insert(&(*root)->left, data);
    } else {
        insert(&(*root)->right, data);
    }
}
void findLevel2Nodes(Node* root) {
    if (root == NULL) {
        return;
    }
    if (root->left != NULL) {
        printf("%d ", root->left->data);
    }
    if (root->right != NULL) {
        printf("%d ", root->right->data);
    }
}

int main() {
    Node* root = NULL;

    // Chèn các nút vào cây
    insert(&root, 4);
    insert(&root, 2);
    insert(&root, 6);
    insert(&root, 1);
    insert(&root, 3);
    insert(&root, 5);
    insert(&root, 7);

    printf("Các đỉnh lớp 2: ");
    findLevel2Nodes(root);
    printf("\n");

    return 0;
}
