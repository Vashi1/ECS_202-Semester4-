//
// Created by romeo on 18/2/23.
//To implement Insertion Sort in C
#include <stdio.h>
void insertion_sort(int arr[], int length){
    int i, key, j;
    for (i = 1; i < length; i++){
        key = arr[i];
        j = i - 1;
        while (j >= 0 && arr[j] > key){
            arr[j + 1] = arr[j];
            j = j - 1;
        }
        arr[j + 1] = key;
    }
    for(int a = 0; a < length; a++){
        printf("%d\n", arr[a]);
    }
    }
int main(){
    int n[] = {7, 1, 5, 2, 4, 3, 6};
    int l = sizeof(n) / sizeof(int);
    insertion_sort(n, l);

}
