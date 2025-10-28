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

int countNodes(Node* root) {
    if (root == NULL) {
        return 0;
    }

    return 1 + countNodes(root->left) + countNodes(root->right);
}

int main() {
    Node* root = createNode(10);
    root->left = createNode(20);
    root->right = createNode(30);
    root->left->left = createNode(40);
    root->left->right = createNode(50);

    int totalNodes = countNodes(root);

    printf("Iniciando contagem de nós...\n");
    printf("O número total de nós na árvore é: %d\n", totalNodes);

    Node* emptyRoot = NULL;
    int totalEmpty = countNodes(emptyRoot);
    printf("O número total de nós na árvore vazia é: %d\n", totalEmpty);

    return 0;
}