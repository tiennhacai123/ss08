#include <stdio.h>
#include <stdlib.h>
#include <limits.h>

// Cấu trúc của một nút trong cây
typedef struct Node {
    int data;
    struct Node* left;
    struct Node* right;
} Node;

// Hàm tạo một nút mới
Node* createNode(int data) {
    Node* newNode = (Node*)malloc(sizeof(Node));
    newNode->data = data;
    newNode->left = NULL;
    newNode->right = NULL;
    return newNode;
}
int isBST(Node* root, int min, int max) {
    if (root == NULL) {
        return 1; // Cây rỗng là cây BST hợp lệ
    }
    if (root->data <= min || root->data >= max) {
        return 0;
    }
    // Kiểm tra cây con bên trái và bên phải
    return isBST(root->left, min, root->data) && isBST(root->right, root->data, max);
}

int main() {
    // Tạo cây nhị phân theo ví dụ
    Node* root = NULL;

    // Cây 1: BST hợp lệ
    root = createNode(10);
    root->left = createNode(5);
    root->right = createNode(15);
    root->left->left = createNode(3);
    root->left->right = createNode(7);
    root->right->left = createNode(12);
    root->right->right = createNode(20);
    
    // Kiểm tra xem cây có phải là BST không
    if (isBST(root, INT_MIN, INT_MAX)) {
        printf("Cay la cay nhii phan tim kiem (BST).\n");
    } else {
        printf("Cay khong la cay nhii phan tim kiem (BST).\n");
    }

    // Cây 2: Không phải BST
    root = createNode(10);
    root->left = createNode(5);
    root->right = createNode(15);
    root->left->left = createNode(6);  
    root->left->right = createNode(7);
    root->right->left = createNode(12);
    root->right->right = createNode(20);

    if (isBST(root, INT_MIN, INT_MAX)) {
        printf("Cay la cay nhii phan tim kiem (BST).\n");
    } else {
        printf("Cay khong la cay nhii phan tim kiem (BST).\n");
    }

    // Cây 3: Cây rỗng (BST hợp lệ)
    root = NULL;

    if (isBST(root, INT_MIN, INT_MAX)) {
        printf("Cay la cay nhii phan tim kiem (BST).\n");
    } else {
        printf("Cay khong la cay nhii phan tim kiem (BST).\n");
    }

    return 0;
}
