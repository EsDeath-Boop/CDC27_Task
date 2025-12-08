#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    void getAllComb(vector<string>& ans,string s,int ob,int cb,int n) {
        if(cb == n) {
            ans.push_back(s);
            return;
        }
        if(ob<n)    getAllComb(ans,s+'(',ob+1,cb,n);
        if(ob>cb)   getAllComb(ans,s+')',ob,cb+1,n);
    } 
    vector<string> generateParenthesis(int n) {
        vector<string>ans;
        getAllComb(ans,"",0,0,n);
        return ans;
    }
};