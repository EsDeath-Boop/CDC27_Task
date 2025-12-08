#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    
    class Solution {
    public:
        bool isAnagram(string s, string t) {
            if(s.length() != t.length())    return false;
            unordered_map<char,int> map1;
            for(int i = 0;i<s.length();i++){
                map1[s[i]]++;
            }
            for(int i = 0;i<s.length();i++){
                char ch = t[i];
                if(map1.find(ch) != map1.end()){
                    map1[ch]--;
                    if(map1[ch] == 0)   map1.erase(ch);
                }
                else return false;
            }
            return true;
        }
    };
    return 0;
}