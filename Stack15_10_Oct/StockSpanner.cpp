#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    
    class StockSpanner {
    private:
        stack<pair<int, int>> st; // pair<price, span>
        
    public:
        StockSpanner() { }
        
        int next(int price) {
            int span = 1;
            // pop all prices <= current price and add their spans
            while (!st.empty() && st.top().first <= price) {
                span += st.top().second;
                st.pop();
            }
            st.push({price, span});
            return span;
        }
    };

    return 0;
}