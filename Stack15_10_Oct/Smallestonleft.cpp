#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    
    vector<int> Smallestonleft(int arr[], int n) {
    vector<int> ans(n);
    set<int> s;   // balanced BST

    for (int i = 0; i < n; i++) {
        auto it = s.lower_bound(arr[i]); // first element >= arr[i]

        if (it == s.begin()) {
            ans[i] = -1;   // no smaller element
        } else {
            --it;          // predecessor = greatest smaller element
            ans[i] = *it;
        }

        s.insert(arr[i]);
    }

    return ans;
}

    return 0;
}