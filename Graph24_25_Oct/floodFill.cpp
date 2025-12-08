#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    void dfs(vector<vector<int>>& image, int currRow, int currCol, int initialColor,int finalColor) {
        int n = image.size();
        int m = image[0].size();
        if(currRow<0 ||currCol<0 || currCol>=m || currRow>=n) {
            return;
        }
        if(image[currRow][currCol] != initialColor) {
            return;
        }
        image[currRow][currCol] = finalColor;
        dfs(image,currRow+1,currCol,initialColor,finalColor);//down
        dfs(image,currRow-1,currCol,initialColor,finalColor);//up
        dfs(image,currRow,currCol-1,initialColor,finalColor);//left
        dfs(image,currRow,currCol+1,initialColor,finalColor);//right
    }
    vector<vector<int>> floodFill(vector<vector<int>>& image, int sr, int sc, int color) {
        if(image[sr][sc] == color)  return image;
        dfs(image,sr,sc,image[sr][sc],color);
        return image;
    }
};