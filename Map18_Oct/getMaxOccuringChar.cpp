#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    
    class Solution {
    public:
        char getMaxOccuringChar(string s) {
            unordered_map<char, int> freq;
            
            for (char c : s) freq[c]++;
            
            int mx = 0;
            char ans = 'z';
            
            for (auto &p : freq) {
                char c = p.first;
                int f = p.second;
                
                if (f > mx) {
                    mx = f;
                    ans = c;
                } else if (f == mx) {
                    ans = min(ans, c);
                }
            }
            
            return ans;
        }
    };

    return 0;
}