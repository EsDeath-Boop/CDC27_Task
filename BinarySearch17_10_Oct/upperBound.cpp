#include <iostream>
using namespace std;

int upper_bound_custom(int a[], int n, int x) {
    int low = 0, high = n;
    while (low < high) {
        int mid = low + (high - low) / 2;
        if (a[mid] <= x) low = mid + 1;
        else high = mid;
    }
    return low;
}

int main() {
    int a[] = {1, 2, 4, 4, 5, 7};
    int n = 6;
    int x = 4;

    int idx = upper_bound_custom(a, n, x);
    cout << idx;

    return 0;
}
