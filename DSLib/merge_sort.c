#include <stdio.h>
#include <stdlib.h>

void merge_sort(int [], int , int );
void merge(int *, int , int , int );

int inv = 0;

int main(int argc, char const *argv[]) {
    int N;
    scanf("%d", &N);

    int arr[N];
    for (int i = 0; i < N; i++) {
        scanf("%d", &arr[i]);
    }

    merge_sort(arr, 0, N-1);

    for (int i = 0; i < N; i++) {
        printf("%d ", arr[i]);
    }
    printf(" Ive %d", inv);
    return 0;
}

void merge_sort(int arr[], int lw, int hi) {
    if (lw >= hi) return;

    int mid = lw + (hi - lw)/2;

    merge_sort(arr, lw, mid);
    merge_sort(arr, mid+1, hi);

    merge(arr, lw, mid, hi);
}

void merge(int *arr, int lw, int mid, int hi) {
    printf("lw: %d, mid: %d, hi: %d\n", lw, mid, hi);
    int i = lw, j = mid + 1;

    int aux[hi];
    for (int k = lw; k <= hi; k++) {
        aux[k] = arr[k];
    }

    for (int k = lw; k <= hi; k++) {
        if (i > mid) {
            arr[k] = aux[j++];
        }
        else if (j > hi) {
            arr[k] = aux[i++];
        }
        else if (aux[j] < aux[i]) {
            arr[k] = aux[j++];
            inv = inv + (mid - i) + 1;
        }
        else {
            arr[k] = aux[i];
            //printf("\n%d\n", inv);
            i++;
        }
    }
}
