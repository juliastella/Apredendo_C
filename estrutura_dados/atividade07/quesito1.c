#include <stdio.h>
#include <stdlib.h>

// --- Estrutura do Nó da Árvore ---
typedef struct Node {
    int data;
    struct Node* left;
    struct Node* right;
} Node;

// --- Estruturas da Fila (para auxiliar na construção) ---
// Nó da fila (armazena um ponteiro para um nó da árvore)
typedef struct QNode {
    Node* treeNode;
    struct QNode* next;
} QNode;

// A Fila em si
typedef struct Queue {
    QNode* front;
    QNode* rear;
} Queue;

// --- Funções Auxiliares (Árvore e Fila) ---

// Cria um novo nó da árvore
Node* createTreeNode(int data) {
    Node* newNode = (Node*)malloc(sizeof(Node));
    if (newNode == NULL) {
        printf("Erro de alocação de memória (Nó da Árvore)!\n");
        exit(1);
    }
    newNode->data = data;
    newNode->left = NULL;
    newNode->right = NULL;
    return newNode;
}

// Cria uma nova fila vazia
Queue* createQueue() {
    Queue* q = (Queue*)malloc(sizeof(Queue));
    if (q == NULL) {
        printf("Erro de alocação de memória (Fila)!\n");
        #include <stdio.h>
        #include <stdlib.h>

        typedef struct Node {
            int data;
            struct Node* left;
            struct Node* right;
        } Node;

        typedef struct QNode {
            Node* treeNode;
            struct QNode* next;
        } QNode;

        typedef struct Queue {
            QNode* front;
            QNode* rear;
        } Queue;

        Node* createTreeNode(int data) {
            Node* newNode = (Node*)malloc(sizeof(Node));
            if (newNode == NULL) {
                printf("Erro de alocação de memória (Nó da Árvore)!\n");
                exit(1);
            }
            newNode->data = data;
            newNode->left = NULL;
            newNode->right = NULL;
            return newNode;
        }

        Queue* createQueue() {
            Queue* q = (Queue*)malloc(sizeof(Queue));
            if (q == NULL) {
                printf("Erro de alocação de memória (Fila)!\n");
                exit(1);
            }
            q->front = q->rear = NULL;
            return q;
        }

        void enqueue(Queue* q, Node* treeNode) {
            QNode* newQNode = (QNode*)malloc(sizeof(QNode));
            if (newQNode == NULL) {
                printf("Erro de alocação de memória (Nó da Fila)!\n");
                exit(1);
            }
            newQNode->treeNode = treeNode;
            newQNode->next = NULL;

            if (q->rear == NULL) {
                q->front = q->rear = newQNode;
                return;
            }

            q->rear->next = newQNode;
            q->rear = newQNode;
        }

        Node* dequeue(Queue* q) {
            if (q->front == NULL) {
                return NULL;
            }

            QNode* temp = q->front;
            Node* treeNode = temp->treeNode;

            q->front = q->front->next;

            if (q->front == NULL) {
                q->rear = NULL;
            }

            free(temp);
            return treeNode;
        }

        Node* buildCompleteTree(int values[], int n) {
            if (n <= 0) {
                return NULL;
            }

            Queue* q = createQueue();

            Node* root = createTreeNode(values[0]);
            enqueue(q, root);

            int i = 1;

            while (i < n) {
                Node* parent = dequeue(q);

                Node* leftChild = createTreeNode(values[i]);
                parent->left = leftChild;
                enqueue(q, leftChild);
                i++;

                if (i < n) {
                    Node* rightChild = createTreeNode(values[i]);
                    parent->right = rightChild;
                    enqueue(q, rightChild);
                    i++;
                }
            }

            free(q);
            return root;
        }

        void printPreOrder(Node* node) {
            if (node == NULL) {
                return;
            }
            printf("%d ", node->data);
            printPreOrder(node->left);
            printPreOrder(node->right);
        }

        int main() {
            int values[100];
            int count = 0;

            printf("Digite uma sequência de números inteiros.\n");
            printf("Para parar, digite 's' ou qualquer letra e pressione Enter:\n");

            while (count < 100 && scanf("%d", &values[count]) == 1) {
                count++;
            }

            if (count == 0) {
                printf("Nenhum número foi inserido.\n");
                return 0;
            }

            printf("\nConstruindo árvore com %d elementos...\n", count);

            Node* root = buildCompleteTree(values, count);

            printf("Árvore em Pré-Ordem (Raiz, Esquerda, Direita):\n");
            printPreOrder(root);
            printf("\n");

            return 0;
        }