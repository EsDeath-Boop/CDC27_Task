#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    
    class Solution {
    public:
        vector<int> asteroidCollision(vector<int>& asteroids) {
            stack<int> st;

            for (int a : asteroids) {
                bool destroyed = false;

                // collision only happens when st.top() > 0 and a < 0
                while (!st.empty() && st.top() > 0 && a < 0) {
                    if (abs(a) > abs(st.top())) {
                        st.pop();          // top asteroid destroyed
                        continue;          // check next possible collision
                    }
                    else if (abs(a) == abs(st.top())) {
                        st.pop();          // both destroy each other
                    }
                    destroyed = true;      // current asteroid destroyed
                    break;
                }

                if (!destroyed) {
                    st.push(a);
                }
            }

            // build result from stack
            vector<int> result(st.size());
            for (int i = st.size() - 1; i >= 0; --i) {
                result[i] = st.top();
                st.pop();
            }

            return result;
        }
    };

    return 0;
}