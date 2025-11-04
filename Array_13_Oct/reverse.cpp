#include <bits/stdc++.h>
using namespace std;

void reverseArray(vector<int> &arr, int m) {
    int n = arr.size();
    
    int left = m + 1;
    int right = n - 1;
    
    while (left < right) {
        swap(arr[left], arr[right]);
        left++;
        right--;
    }
}

int main() {
    int t;
    cin >> t;
    
    while (t--) {
        int n, m;
        cin >> n >> m;
        
        vector<int> arr(n);
        for (int i = 0; i < n; i++) {
            cin >> arr[i];
        }
        
        reverseArray(arr, m);
        for (int i = 0; i < n; i++) {
            cout << arr[i];
            if (i < n - 1) cout << " ";
        }
        cout << endl;
    }
    
    return 0;
}