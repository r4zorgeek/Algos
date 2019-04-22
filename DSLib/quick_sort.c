#include <stdio.h>
#include <stdlib.h>

// prototype
int partition(int *, int , int );

void quick_sort(int *, int , int );

// prototype
void swap(int *, int *);

int main(int argc, char const *argv[]) {
    int N;
    scanf("%d", &N);

    int arr[N];
    for (int i = 0; i < N; i++) {
        scanf("%d", &arr[i]);
    }

    quick_sort(arr, 0, N-1);

    for (int i = 0; i < N; i++) {
        printf("%d ", arr[i]);
    }
    printf("\n");

    return 0;
}

void swap(int *a, int *b) {
    int temp = *a;
    *a = *b;
    *b = temp;
}

void quick_sort(int *arr, int lo, int hi) {
    if (lo >= hi) return;
    int p_index = partition(arr, lo, hi);

    quick_sort(arr, lo, p_index-1);
    quick_sort(arr, p_index+1, hi);
}

int partition(int *arr, int lo, int hi) {
    int pivot = arr[hi];
    int p_index = lo;

    for (int i = lo; i < hi; i++) {
        if (arr[i] < pivot) {
            swap(&arr[i], &arr[p_index]);
            p_index++;
        }
    }
    swap(&arr[p_index], &arr[hi]);

    return p_index;
}
