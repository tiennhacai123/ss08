#include <stdio.h>
#include <stdlib.h>

// Cấu trúc một nút trong cây nhị phân tìm kiếm
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

// Hàm chèn giá trị mới vào cây nhị phân tìm kiếm
Node* insert(Node* root, int data) {
    if (root == NULL) {
        return createNode(data);
    }

    if (data < root->data) {
        root->left = insert(root->left, data);
    } else if (data > root->data) {
        root->right = insert(root->right, data);
    }

    return root;
}

// Hàm tìm kiếm một giá trị trong cây nhị phân tìm kiếm
int search(Node* root, int x) {
    if (root == NULL) {
        printf("Not Found\n");
        return 0;
    }

    if (root->data == x) {
        printf("Found\n");
        return 1;
    }

    if (x < root->data) {
        return search(root->left, x);
    } else {
        return search(root->right, x);
    }
}

int main() {
    Node* root = NULL;
    int values[] = {20, 10, 30, 5, 15, 25, 35};
    int n = sizeof(values) / sizeof(values[0]);

    for (int i = 0; i < n; i++) {
        root = insert(root, values[i]);
    }

    int searchValue;

    printf("Enter value to search: ");
    scanf("%d", &searchValue);

    // Tìm kiếm giá trị trong cây
    search(root, searchValue);

    return 0;
}
