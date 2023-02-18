//
// Created by romeo on 18/2/23.
//To implement Insertion Sort in C
#include <stdio.h>
void bubble_sort(int arr[], int length){
    for (int i = 0; i < length - 1; i++){
        int flag = 0;
        for(int j = 0; j < length -1 - i; j++){
            if (arr[j] > arr[j + 1]){
                int temp = arr[j];
                arr[j] = arr[j + 1];
                arr[j + 1] = temp;
                flag = 1;
            }
        }
        if (flag == 0){
            break;
        }
    }
    for(int a = 0; a < length; a++){
        printf("%d\n", arr[a]);
    }
}

int main(){
    int n[] = {16, 14, 5, 6, 8};
    int l = sizeof(n) / sizeof(int);
    bubble_sort(n, l);

}
