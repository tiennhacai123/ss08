#include <stdio.h>
#include <stdlib.h>

// Cấu trúc của một nút trong cây
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

Node* insert(Node* root, int data) {
    if (root == NULL) {
        return createNode(data);  
    }

    if (data < root->data) {
        root->left = insert(root->left, data);  
    } else {
        root->right = insert(root->right, data);  
    }

    return root;
}

int search(Node* root, int data) {
    if (root == NULL) {
        return 0; 
    }

    if (data == root->data) {
        return 1; 
    }

    if (data < root->data) {
        return search(root->left, data); 
    } else {
        return search(root->right, data); 
    }
}

void inorder(Node* root) {
    if (root != NULL) {
        inorder(root->left); 
        printf("%d ", root->data);  
        inorder(root->right);  
    }
}

void freeTree(Node* root) {
    if (root != NULL) {
        freeTree(root->left);
        freeTree(root->right);
        free(root);
    }
}

int main() {
    Node* root = NULL;

    // Trường hợp 1: Chèn và duyệt cây
    int values1[] = {5, 3, 7, 2, 4, 6, 8};
    int n1 = sizeof(values1) / sizeof(values1[0]);
    
    // Chèn các giá trị vào cây
    for (int i = 0; i < n1; i++) {
        root = insert(root, values1[i]);
    }

    // Duyệt cây theo thứ tự inorder và in kết quả
    printf("Duyet cay theo thu tu inorder: ");
    inorder(root);
    printf("\n");

    // Trường hợp 2: Tìm kiếm giá trị trong cây (có tồn tại)
    int searchValue1 = 7;
    if (search(root, searchValue1)) {
        printf("Gia tri %d ton tai trong cay.\n", searchValue1);
    } else {
        printf("Gia tri %d khong ton tai trong cay.\n", searchValue1);
    }

    // Trường hợp 3: Tìm giá trị trong cây (không tồn tại)
    int searchValue2 = 8;
    if (search(root, searchValue2)) {
        printf("Gia tri %d ton tai trong cay.\n", searchValue2);
    } else {
        printf("Gia tri %d khong ton tai trong cay.\n", searchValue2);
    }

    freeTree(root);

    return 0;
}
