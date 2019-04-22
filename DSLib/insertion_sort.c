#include <stdio.h>
#include <stdlib.h>

// prototype
void insertion_sort(int *, int );

int main(int argc, char const *argv[]) {
    int N;
    scanf("%d", &N);

    int arr[N];
    for (int i = 0; i < N; i++) {
        scanf("%d", &arr[i]);
    }

    insertion_sort(arr, N);

    // print sorted array
    printf("Sorted Array\n");
    for (int i = 0; i < N; i++) {
        printf("%d ", arr[i]);
    }

    return 0;
}

void insertion_sort(int *arr, int N) {
    for (int i = 0; i < N; i++) {

        int temp = arr[i];
        int j = i;

        while (j > 0 && temp < arr[j - 1]) {
            arr[j] = arr[j - 1];
            j = j - 1;
        }
        arr[j] = temp;
    }
}
