#include <stdio.h>
#include <tgmath.h>


void swap(int n, double mat[n][n], int from, int to) {
    double tmp;
    for (int i = 0; i < n; i++) {
        tmp = mat[from][i];
        mat[from][i] = mat[to][i];
        mat[to][i] = tmp;
    }
}



int trngl(int n, double mat[n][n]) {
    int sw = 0;
    for (int i = 0; i < n; i++) {
        double max = -1;
        int from = 0;
        for (int j = i; j < n; j++) {
            if (fabs(mat[j][i]) > max) {
                max = mat[j][i];
                from = j;
            }
        }
        if (from != i) {
            swap(n, mat, from, i);
            sw++;
        }

        for (int j = i + 1; j < n; j++) {
            double multiplier = mat[j][i]/mat[i][i];
            for (int k = i + 1; k < n; k++) {
                mat[j][k] = mat[j][k] - multiplier*mat[i][k];
            }
        }
    }
    return sw;
}

double det(int n, double mat[n][n], int s) {
    double res = 1;
    for (int i = 0; i < n; i++) {
        res *= mat[i][i];
    }
    if (s % 2 == 0) {
        return res;
    }else {
        return -res;
    }
}


int main() {
    int n;
    scanf("%d", &n);

    double matrix[n][n];
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            scanf("%lf", &matrix[i][j]);
        }
    }
    int s;
    s = trngl(n, matrix);
    printf("%lf", det(n, matrix, s));

}