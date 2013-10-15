#include <cassert>
#include <iostream>

int quicksort(int A[], int n, int target) {
    int from = 0;
    int to = n - 1;
    while (from <= to) {
        int mid = (from + to) / 2;
        if (A[mid] == target) return mid;
        if (A[mid] < target) {
            from = mid + 1;
        } else {
            to = mid - 1;
        }
    }
    return -1;
}

int main() {
    {
        int A[] = {1, 2, 3, 5, 7, 9, 10, 11};
        assert(quicksort(A, sizeof(A), 11) == 7);
    }
    {
        int A[] = {1, 2, 3, 5, 7, 9, 10, 11};
        assert(quicksort(A, sizeof(A), 0) == -1);
    }
    {
        int A[] = {1, 2, 3, 5, 7, 9, 10, 11};
        assert(quicksort(A, sizeof(A), 7) == 4);
    }
    {
        int A[] = {1, 2, 3, 5, 7, 9, 10, 11};
        assert(quicksort(A, sizeof(A), 1) == 0);
    }
}

