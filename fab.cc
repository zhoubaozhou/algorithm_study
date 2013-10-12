#include <iostream>
#include <stack>

const int kReturnResult = 1;
const int KComputeAndReturn = 2;
const int kCall = 3;

int pop(std::stack<int>& heap) {
    int num = heap.top();
    heap.pop();
    return num;
}

int fac(int n) {
    std::stack<int> heap;
    heap.push(kReturnResult);
    heap.push(n);
    heap.push(kCall);
    while(!heap.empty()) {
        int op = pop(heap);
        switch (op) {
            case kCall: {
                n = pop(heap);
                if (n < 2) {
                    op = pop(heap);
                    heap.push(1);
                    heap.push(op);
                } else {
                    heap.push(n);
                    heap.push(KComputeAndReturn);
                    heap.push(n-1);
                    heap.push(kCall);
                }
                break;
            }
            case KComputeAndReturn: {
                int tmp_fac = pop(heap);
                n = pop(heap);
                op = pop(heap);
                tmp_fac = tmp_fac * n;
                heap.push(tmp_fac);
                heap.push(op);
                break;
            }
            case kReturnResult: {
                return pop(heap);
                break;
            }
        }
    }
    return 0;
}

int main() {
    std::cout << fac(5) << std::endl;
}
