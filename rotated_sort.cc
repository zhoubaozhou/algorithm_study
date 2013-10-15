#include <iostream>

class Solution {
public:
    int binary_search(int A[], int from, int to, int target) {
        if (to <= from && A[to] != target) return -1;
        int mid = (from + to)/2;
        int cmp = target - A[mid];
        if (cmp > 0) {
            return binary_search(A, mid+1, to, target);
        } else if (cmp < 0) {
            return binary_search(A, from, mid, target);
        } else {
            return mid;
        }
    }
    
    int search(int A[], int n, int target) {
        // Note: The Solution object is instantiated only once and is reused by each test case.
        if (n == 0) return -1;
        if (n == 1) {
            if (A[0] == target) {
                return 0;
            } else {
                return -1;
            }
        }
        // 拆分区间
        int pivot = n - 1;
        for (int i=n-1; i>=0 && pivot > 0; --i) {
            if(A[pivot-1] < A[i]) {
                pivot--;
                continue;
            }
        }
        std::cout << pivot << std::endl;
        // 分两个区间进行二分查找
        if (pivot > 0) {
            int ret = binary_search(A, 0, pivot, target);
            if (ret >= 0) return ret;
        }
        if (pivot <= n - 1 && pivot >= 0) {
            return binary_search(A, pivot, n, target);
        }
        return -1;
    }
};

int main() {
    int A[] = {3, 1};
    Solution solution;
    std::cout << solution.search(A, 2, 1) << std::endl;
    return 0;
}
