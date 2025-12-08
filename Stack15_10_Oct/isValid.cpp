#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    
    class Solution {
    public:
        bool isValid(string s) {
            stack<char>st;
            for(int i = 0; i < s.size(); i++) {
                if(st.empty() || s[i] == '(' || s[i] == '{' || s[i] == '[') {
                    st.push(s[i]);
                    continue;
                } else if(s[i] == ')') {
                    if(st.top() == '(') {
                        st.pop();
                        continue;
                    } else return false;
                } else if(s[i] == '}') {
                    if(st.top() == '{') {
                        st.pop();
                        continue;
                    } else return false;
                } else if(s[i] == ']') {
                    if(st.top() == '[') {
                        st.pop();
                        continue;
                    } else return false;
                }
            }
            return st.empty();
        }
    };

    return 0;
}