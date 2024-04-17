#include <stdio.h>
void multiply_mat(int n, double a[n][n], double b[n], double res[n]) {
    for (int i = 0; i < n; i++) {
        for(int j = 0; j < n; j++) {
            res[i] = 0;
        for (int k = 0; k < n; k++) {
            res[i] += a[i][k] * b[k];
            }
        }
    }
}

double find_max(int n, double mat[n]) {
    double max = mat[0];
    for (int i = 1; i < n; i++) {
        if (max < mat[i]) {
            max = mat[i];
        }
    }

    return max;
}

int main() {
    int n, iter;
    printf("Enter dimensions of the matrix: ");
    scanf("%d", &n);

    printf("Enter max iterations: ");
    scanf("%d", &iter);

    double a[n][n], eigen_vector[n], x[n], eigen_value = 0;

    for (int i = 0; i < n; i++) {
        eigen_vector[i] = 1;
        for (int j = 0; j < n; j++) {
            scanf("%lf", &a[i][j]);
        }
    }

    for (int i = 0; i < iter; i++) {
        multiply_mat(n, a, eigen_vector, x);
        eigen_value = find_max(n, x);
        for (int i = 0; i < n; i++) {
            x[i] /= eigen_value;
            eigen_vector[i] = x[i];
        }
    }

    printf("The dominant eigen value is %lf\n", eigen_value);

    printf("Its corresponding eigen vector is [ ");
    for (int i = 0; i < n; i++) {
        printf("%lf ", eigen_vector[i]);
    }
    printf("]\n");
}