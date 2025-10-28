#include <stdio.h>
#include <stdlib.h>

typedef struct Node {
    int data;
    struct Node* left;
    struct Node* right;
} Node;

Node* createNode(int data) {
    Node* newNode = (Node*)malloc(sizeof(Node));
    if (newNode == NULL) {
        printf("Erro de alocação de memória!\n");
        exit(1);
    }
    newNode->data = data;
    newNode->left = NULL;
    newNode->right = NULL;
    return newNode;
}


void printInOrder(Node* root) {
    if (root == NULL) {
        return;
    }

    printInOrder(root->left);

    printf("%d ", root->data);

    printInOrder(root->right);
}

int main() {
    Node* root = createNode(10);
    root->left = createNode(20);
    root->right = createNode(30);
    root->left->left = createNode(40);
    root->left->right = createNode(50);
    root->right->left = createNode(60);

    printf("Imprimindo a árvore em Ordem Simétrica (Em-Ordem):\n");

    printInOrder(root);

    printf("\n");

    return 0;
}