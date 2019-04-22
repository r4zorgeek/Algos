#include <stdio.h>
#include <stdlib.h>

#define N 7

void build_heap(int *, int );

void max_heapify(int *, int );

void swap(int *, int *);


int main(int argc, char const *argv[]) {
    int arr[N] = {1, 4, 3, 7, 8, 9, 10};
    build_heap(arr, N);
    for (int i = 0; i < N; i++) {
        printf(" %d", arr[i]);
    }

    return 0;
}

void build_heap(int *arr, int n) {
    for (int i = (n/2 - 1); i >= 0; i--) {
        max_heapify(arr, i);
    }
}

void max_heapify(int *arr, int i) {
    int largest;
    int left_child = (2 * i) + 1;
    int right_child = (2 * i) + 2;

    if (left_child < N && arr[left_child] > arr[i]) {
        largest = left_child;
    }
    else {
        largest = i;
    }

    if (right_child < N && arr[right_child] > arr[largest]) {
        largest = right_child;
    }
    if (largest != i) {
        swap(&arr[i], &arr[largest]);
        max_heapify(arr, largest);
    }

}

void swap(int *a, int *b) {
    int temp = *a;
    *a = *b;
    *b = temp;
}
