//
// Created by romeo on 18/2/23.
//
#include <stdio.h>
#include <stdlib.h>
int main(){
    char ch, *num;
    size_t size = 1, index = 0;
    printf("Please enter a positive integer (without sign");
    fflush(stdin);
    num = (char *) malloc(size * sizeof(char));
    while (EOF != (ch = getchar()) && ch >= '0' && ch <= '9'){
        num[index++] = ch;
        if (index == size){
            num = (char *) realloc(num, size *= 2);
            if (num == NULL){
                exit(1);
            }
        }
    }
    num = (char *) realloc(num, index); if (num == NULL) exit(1);
    printf("The entered number is:");
    for (int j = 0; j < index; j++){
        putchar(num[j]);
    }
        printf("\n");
        free(num);
        return 0;
}