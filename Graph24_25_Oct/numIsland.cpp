#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    int numIslands(vector<vector<char>>& grid) {
        int rows = grid.size();
        int cols = grid[0].size();
        int cc = 0;//connected Components
        for(int i = 0;i<rows;i++) {
            for(int j = 0;j<cols;j++) {
                if(grid[i][j] == '0') {
                    //it is a water body
                    continue;
                }
                cc++;
                grid[i][j] = '0';
                queue<pair<int,int>>q;
                q.push({i,j});
                while(q.size()) {
                    auto curr = q.front();
                    q.pop();
                    int currRow = curr.first;
                    int currCol = curr.second;
                    //check up
                    if(currRow-1>=0 && grid[currRow-1][currCol] == '1') {
                        q.push({currRow-1,currCol});
                        grid[currRow-1][currCol] = '0';
                    }
                    //check down
                    if(currRow+1<rows && grid[currRow+1][currCol] == '1') {
                        q.push({currRow+1,currCol});
                        grid[currRow+1][currCol] = '0';
                    }
                    //check left
                    if(currCol-1>=0 && grid[currRow][currCol-1] == '1') {
                        q.push({currRow,currCol-1});
                        grid[currRow][currCol-1] = '0';
                    }
                    //check right
                    if(currCol+1<cols && grid[currRow][currCol+1] == '1') {
                        q.push({currRow,currCol+1});
                        grid[currRow][currCol+1] = '0';
                    }
                }
            }
        }
        return cc;
    }
};