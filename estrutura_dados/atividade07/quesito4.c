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

Node* insertBST(Node* root, int data) {
    if (root == NULL) {
        return createNode(data);
    }

    if (data < root->data) {
        root->left = insertBST(root->left, data);
    } else if (data > root->data) {
        root->right = insertBST(root->right, data);
    }

    return root;
}

int searchBST(Node* root, int key) {
    if (root == NULL) {
        return 0;
    }

    if (root->data == key) {
        return 1;
    }

    if (key < root->data) {
        return searchBST(root->left, key);
    } else {
        return searchBST(root->right, key);
    }
}

int main() {
    Node* root = NULL;

    root = insertBST(root, 50);
    root = insertBST(root, 30);
    root = insertBST(root, 70);
    root = insertBST(root, 20);
    root = insertBST(root, 40);
    root = insertBST(root, 60);
    root = insertBST(root, 80);

    printf("Árvore Binária de Busca criada.\n\n");

    int val1 = 40;
    printf("Buscando %d... %s\n",
           val1,
           searchBST(root, val1) ? "Encontrado!" : "Não encontrado!");

    int val2 = 99;
    printf("Buscando %d... %s\n",
           val2,
           searchBST(root, val2) ? "Encontrado!" : "Não encontrado!");

    int val3 = 50;
    printf("Buscando %d... %s\n",
           val3,
           searchBST(root, val3) ? "Encontrado!" : "Não encontrado!");

    int val4 = 20;
    printf("Buscando %d... %s\n",
           val4,
           searchBST(root, val4) ? "Encontrado!" : "Não encontrado!");

    return 0;
}