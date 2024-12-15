#include<stdio.h>
#include<stdlib.h>
# define MAX 5
// cấu trúc dữ liệu cho nut
typedef struct Node{
    int data;
    struct Node* left;
    struct Node* right;
}Node;

// khởi tạo ra 1 nút
Node* createNode(int data){
    // khởi tạo bộ nhớ động bằng mallo
    Node* newNode = (Node*) malloc(sizeof(Node));
    newNode->data = data;
    newNode->left = NULL;
    newNode->right = NULL;
    return newNode;
}

// chèn 1 nút vào cây
Node* insertNode(Node*  node, int data){
    if(node == NULL){
        // nếu cây rỗng thì sẽ gọi lại hàm createNode để tạo ra 1 nút mới 
        return createNode(data);
    }
        if(data < node->data){
             node->left = insertNode(node->left, data);
        }else if(data > node->data){
             node->right = insertNode(node->right, data);
        }
        return node;
    
}

//duyệt cây theo prevorder(duyet truoc)
void prevorderTraversal(Node* node){
    if(node != NULL){
        printf("%d\t", node->data);
        prevorderTraversal(node->left);
        prevorderTraversal(node->right);
    }
}

// duyejt theo inoder(duyet giua)
void inorderTraversal(Node* node){
    if(node != NULL){
        inorderTraversal(node->left);
        printf("%d\t", node->data);
        inorderTraversal(node->right);
    }
}

// duyet theo Post Order (duyet sau)
void postTraversal(Node* node){
    if(node != NULL){
    postTraversal(node->left);
    postTraversal(node->right);
    printf("%d\t", node->data);
    }
}
int main(){
    Node* node = NULL;
    // chen 
    node = insertNode(node,4);
    node = insertNode(node,2);
    node = insertNode(node,5);
    node = insertNode(node,1);
    node = insertNode(node,3);
// in ra 
    printf("Duyet theo tien thu tu: \n");
    prevorderTraversal(node);

    printf("\nduyet trung thu tu: \n");
    inorderTraversal(node);

    printf("\nDuyet hau thu tu: \n");
    postTraversal(node);
    return 0;
}