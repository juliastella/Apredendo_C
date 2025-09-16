#include <stdio.h>

int main() {
    int m, r, n;
    int i, j, k;

    printf("Digite m (linhas da matriz A): ");
    scanf("%d", &m);
    printf("Digite r (colunas de A e linhas de B): ");
    scanf("%d", &r);
    printf("Digite n (colunas da matriz B): ");
    scanf("%d", &n);

    int A[m][r], B[r][n], C[m][n];

    printf("\nDigite os elementos da matriz A (%dx%d):\n", m, r);
    for (i = 0; i < m; i++) {
        for (j = 0; j < r; j++) {
            printf("A[%d][%d]: ", i, j);
            scanf("%d", &A[i][j]);
        }
    }

    printf("\nDigite os elementos da matriz B (%dx%d):\n", r, n);
    for (i = 0; i < r; i++) {
        for (j = 0; j < n; j++) {
            printf("B[%d][%d]: ", i, j);
            scanf("%d", &B[i][j]);
        }
    }

    for (i = 0; i < m; i++) {
        for (j = 0; j < n; j++) {
            C[i][j] = 0;
        }
    }

    for (i = 0; i < m; i++) {
        for (j = 0; j < n; j++) {
            for (k = 0; k < r; k++) {
                C[i][j] += A[i][k] * B[k][j];
            }
        }
    }

    printf("\nMatriz resultado C (%dx%d):\n", m, n);
    for (i = 0; i < m; i++) {
        for (j = 0; j < n; j++) {
            printf("%d\t", C[i][j]);
        }
        printf("\n");
    }

    return 0;
}
