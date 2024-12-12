#include <stdio.h>
#include <stdlib.h>
#include <time.h>

void bubbleSort(int arr[], int n, int *comparisons, int *swaps) {
    int temp;
    int i, j;
    *comparisons = 0;
    *swaps = 0;
    for (i = 0; i < n-1; i++) {
        for (j = 0; j < n-i-1; j++) {
            (*comparisons)++;
            if (arr[j] > arr[j+1]) {
                temp = arr[j];
                arr[j] = arr[j+1];
                arr[j+1] = temp;
                (*swaps)++;
            }
        }
    }
}

void selectionSort(int arr[], int n, int *comparisons, int *swaps) {
    int i, j, minIdx, temp;
    *comparisons = 0;
    *swaps = 0;
    for (i = 0; i < n-1; i++) {
        minIdx = i;
        for (j = i+1; j < n; j++) {
            (*comparisons)++;
            if (arr[j] < arr[minIdx]) {
                minIdx = j;
            }
        }
        if (minIdx != i) {
            temp = arr[i];
            arr[i] = arr[minIdx];
            arr[minIdx] = temp;
            (*swaps)++;
        }
    }
}

void generateArray(int arr[], int n) {
    int i;
    for (i = 0; i < n; i++) {
        arr[i] = rand() % 1000;
    }
}

void displayComplexities(const char *algorithm, const char *worst, const char *average, const char *best) {
    printf("%s Algorithm Complexities:\n", algorithm);
    printf("Worst-case (T): %s\n", worst);
    printf("Average-case (O): %s\n", average);
    printf("Best-case (O): %s\n\n", best);
}

void analyzePerformance(const char *algorithm, int comparisons, int swaps, int n) {
    printf("%s Performance Analysis:\n", algorithm);
    if (swaps == 0) {
        printf("Case: Best-case (O)\n\n");
    } else if (comparisons == n * (n - 1) / 2 && swaps > 0) {
        printf("Case: Worst-case (T)\n\n");
    } else {
        printf("Case: Average-case (O)\n\n");
    }
}

int main() {
    int n, i;
    clock_t start, end;

    printf("Enter array size: ");
    scanf("%d", &n);

    int arr1[1000];
    int arr2[1000];
    int comparisons, swaps;

    generateArray(arr1, n);
    for (i = 0; i < n; i++) {
        arr2[i] = arr1[i];
    }

    printf("Sorting and measuring execution time...\n\n");

    start = clock();
    bubbleSort(arr1, n, &comparisons, &swaps);
    end = clock();
    printf("Bubble Sort time: %.6f seconds\n", (double)(end - start) / CLOCKS_PER_SEC);
    analyzePerformance("Bubble Sort", comparisons, swaps, n);

    start = clock();
    selectionSort(arr2, n, &comparisons, &swaps);
    end = clock();
    printf("Selection Sort time: %.6f seconds\n", (double)(end - start) / CLOCKS_PER_SEC);
    analyzePerformance("Selection Sort", comparisons, swaps, n);

    // Display algorithm complexities
    displayComplexities("Bubble Sort", "O(n^2)", "O(n^2)", "O(n)");
    displayComplexities("Selection Sort", "O(n^2)", "O(n^2)", "O(n^2)");

    return 0;
}

