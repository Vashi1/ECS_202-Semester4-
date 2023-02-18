//To find the determinant of a matrix
// Created by romeo on 18/2/23.
//
#include <stdio.h>
#include <stdlib.h>
#include <math.h>
void printmat(int **, int);
void createsubmat(int **mat, int **submat, int n, int ii, int jj){
    int i, j;
    for (i = 0; i < n; i++){
        for(j = 0; j < n; j++){
            if (i < ii && j < jj){
                submat[i][j] = mat[i][j];
            }
            else if (i > ii && j < jj){
                submat[i-1][j] = mat[i][j];
            }
            else if (i < ii && j > jj){
                submat[i][j - 1] = mat[i][j];
            }
            else if (i > ii && j > jj){
                submat[i - 1][j - 1] = mat[i][j];
            }
        }
    }
}
void freemat(int **mat, int n){
    for(int i = 0; i < n; i++){
        free(mat[i]);
    }
    free(mat);
}
int determinant(int **mat, int n){
    int det = 0, **submat, i, j;
    if(n == 1){
        return mat[0][0];
    }
    else if(n > 1){
        for(i = 0; i < n; i++){
            submat = (int **)malloc((n-1) * sizeof(int*));
            for (j = 0; j < n - 1; j++){
                submat[j] = (int*) malloc((n-1)*sizeof(int));
                }
            createsubmat(mat, submat, n, i, 0);
            printmat(submat, n - 1);
            det += mat[i][0] * pow(-1, i)* determinant(submat, n - 1);
            freemat(submat, n -1);
            }
        }
    else{
        printf("\nNegative\n");
        return 0;
    }
    return det;
}

void printmat(int **mat, int n){
    printf("-------------------\n");
    for(int i = 0; i < n; i++){
        for(int j = 0; j < n; j++){
            printf("%3d\t", mat[i][j]);
        }
        printf("\n");
    }
    printf("\n--------------------");
}
int main(){
    int det, n, **mat, i, j;
    printf("Please enter the size of matrix");
    scanf("%d", &n);

    mat = (int **) malloc(n*sizeof(int *));
    if (mat = NULL){
        printf("Could not allocate the memory\n");
        exit(1);
    }
    for(i = 0; i < n; i++){
        mat[i] = (int *) malloc(n*sizeof(int));
        if (mat[i] == NULL){
            printf("Could not allocate the memory\n");
            freemat(mat, i - 1);
            exit(1);
        }
    }
    printf("Enter %d matrix entries", n * n);
    for(i = 0; i < n; i++){
        for (j = 0; j < n; j++){
            scanf("%d", &mat[i][j]);
        }
    }
    printmat(mat, n);
    det = determinant(mat, n);
    printf("\ndet = %d\n", det);
    freemat(mat, n);
    return 0;
}