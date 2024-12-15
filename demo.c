#include<stdio.h>
#include<stdlib.h>
# define MAX 5

// cấu trúc dư liệu cho nút
typedef struct Node{
    int data;
    struct Node* left;
    struct Node* right;
}Node;

// tạo ra 1 nút
Node* createNode(int data){
    // cấp phát bộ nhớ động
    Node* newNode = (Node*) malloc(sizeof(Node));
    newNode->data = data;
    newNode->left = NULL;
    newNode->right = NULL;
    return newNode;
}

// chèn 1 nút vào cây
Node* insertNode(Node* node, int data){
    if(node==NULL){
        return createNode(data);
    }
    
    if(data < node->data){
        node->left = insertNode(node->left, data);
    }else if(data > node->data){
        node->right = insertNode(node->right, data);
        return node;
}
}

// duyệt cây theo phương pháp duyêt trước (gốc->trái->phải);
void  preoderTraversal(Node* node){
    if(node != NULL){
        printf("%d\t", node->data);
        preoderTraversal(node->left);
        preoderTraversal(node->right);
    }
}
// duyệt cây theo pp duyệt giưã (trái giữa phải)
void inorderTraversal(Node* node){
    if(node != NULL){
        inorderTraversal(node->left);
        printf("%d\t", node->data);
        inorderTraversal(node->right);
    }
}

// duyệt cây theo pp. duyệt sau. (trái phải giữa)
void postTraversal(Node*  node){
    if(node != NULL){
        postTraversal(node->left);
        postTraversal(node->right);
        printf("%d \t", node->data);
    }
}
// duyệt theo chiều rộng( duyệt theo từng cấp  từ cấp 0 là gốc)
int main(){
    Node*  node = NULL;

    // chèn
    node = insertNode(node,3);
    node = insertNode(node,2);
    node = insertNode(node,5);
    node = insertNode(node,4);
    node = insertNode(node,6);
    
    // in ra 
    preoderTraversal(node);
    printf("\n");
    inorderTraversal(node);
    printf("\n");
    postTraversal(node);
    return 0;
}  
