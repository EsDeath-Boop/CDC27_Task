#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    bool isValid(vector<vector<char>>& board,int r,int c,int j) {
        for(int i = 0; i < 9; i++) {
            if(board[i][c] - '0' == j)  return false;
        }
        for(int i = 0; i < 9; i++) {
            if(board[r][i] - '0'== j)  return false;
        }
        int x = (r/3)*3;
        int y = (c/3)*3;
        for(int a = x; a < x+3; a++) {
            for(int b = y; b < y+3; b++) {
                if(board[a][b] -'0' == j)  return false;
            }
        }
        return true;
    }
    bool solver(vector<vector<char>>& board,int r,int c) {
        if(r == 9)  return true;
        if(c == 9)  return solver(board,r+1,0);
        if(board[r][c] != '.')  return solver(board,r,c+1);
        for(int j = 1; j <= 9; j++) {
            if(isValid(board,r,c,j)) {
                board[r][c] = '0' + j;
                int x = solver(board,r,c+1);
                if(x) return true;
                board[r][c] = '.';
            }
        }
        return false;
    }
    void solveSudoku(vector<vector<char>>& board) {
        solver(board,0,0);
    }
};