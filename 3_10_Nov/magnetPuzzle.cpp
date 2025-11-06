// Write Python3 code here
#include<bits/stdc++.h>
using namespace std;

bool checkConstraints(vector<vector<char>> &rules){
  int M = 5;
  int N = 6;
  vector<int> top = { 1, -1, -1, 2, 1, -1 };
  vector<int> bottom = {2, -1, -1, 2, -1, 3 };
  vector<int> left = {2, 3, -1, -1, -1};
  vector<int> right = {-1, -1, -1, 1, -1};

  vector<int> pCountH(rules.size(), 0);
  vector<int> nCountH(rules.size(), 0);

  for(int row = 0; row < rules.size(); row++){
    for(int col = 0; col < rules[0].size(); col++){
      char ch = rules[row][col];
      if(ch == '+'){
        pCountH[row] += 1;
      }
      else if(ch == '-'){
        nCountH[row] += 1;
      }
    }
  }


  vector<int> pCountV(rules[0].size(), 0);
  vector<int> nCountV(rules[0].size(), 0);
  for(int col = 0; col < rules[0].size(); col++){
    for(int row = 0; row < rules.size(); row++){
      char ch = rules[row][col];
      if(ch == '+'){
        pCountV[col] += 1;
      }
      else if(ch == '-'){
        nCountV[col] += 1;
      }
    }
  }

  for(int row = 0; row < rules.size(); row++){
    if(left[row] != -1){
      if(pCountH[row] != left[row]){
        return false;
      }
    }

    if (right[row] != -1){
      if(nCountH[row] != right[row]){
        return false;
      }
    }

  }


  for(int col = 0; col < rules[0].size(); col++){
    if(top[col] != -1){
      if(pCountV[col] != top[col]){
        return false;
      }
    }

    if(bottom[col] != -1){
      if(nCountV[col] != bottom[col]){
        return false;
      }
    }
    // if (top[col] != -1 and pCountH[col] != top[col]) or (bottom[col] != -1 and nCountH[col] != bottom[col]) :
    // return False
  } 


  return true;    
}



bool canPutPatternHorizontally(vector<vector<char>> &rules,int i,int j, string pat){
  if( j-1>=0 and rules[i][j-1] == pat[0]){
    return false;
  } 
  else if(i-1>=0 and rules[i-1][j] == pat[0]){
    return false;
  }   
  else if(i-1>=0 and rules[i-1][j+1] == pat[1]){
    return false;
  }    
  else if(j+2 < rules[0].size() and rules[i][j+2] == pat[1]){
    return false;
  }
  return true;   
}





bool canPutPatternVertically(vector<vector<char>> &rules,int i,int j, string pat){
  if( j-1>=0 and rules[i][j-1] == pat[0]){
    return false;
  }
  else if(i-1>=0 and rules[i-1][j] == pat[0]){
    return false;
  }
  else if(j+1 < rules[0].size() and rules[i][j+1] == pat[0]){
    return false;
  }

  return true;   
}




void solveMagnets(vector<vector<char>> &rules, int i,int j){

  // check the constraint before printing
  if( i == rules.size() and j == 0){
    if(checkConstraints(rules)){

      // Printing rules array. 
      cout << "[";
      for(int indxi = 0; indxi < rules.size(); indxi++){
        cout << "[";
        for(int indxj = 0; indxj < rules[0].size(); indxj++){
          cout <<"'"<< rules[indxi][indxj] << "', ";
        }
        cout << "]";
      }
      cout << "]";
    }

  }
  else if(j >= rules[0].size()){
    solveMagnets(rules, i+1, 0);
  }
  // normal cases
  else{

    if (rules[i][j] == 'L'){

      // option 1 +-
      if(canPutPatternHorizontally(rules,i,j,"+-")){
        rules[i][j] = '+';
        rules[i][j+1] = '-';

        solveMagnets(rules,i,j+2);

        rules[i][j] = 'L';
        rules[i][j+1] = 'R';
      }

      // option 2 -+
      if(canPutPatternHorizontally(rules,i,j,"-+")){
        rules[i][j] = '-';
        rules[i][j+1] = '+';

        solveMagnets(rules,i,j+2);

        rules[i][j] = 'L';
        rules[i][j+1] = 'R';            
      }

      // option 3 xx
      if((1 == 1) || canPutPatternHorizontally(rules,i,j,"xx")){
        rules[i][j] = 'x';
        rules[i][j+1] = 'x';

        solveMagnets(rules,i,j+2);

        rules[i][j] = 'L';
        rules[i][j+1] = 'R';         
      }

    }
    // vertical check
    else if(rules[i][j] == 'T'){
      if(canPutPatternVertically(rules,i,j,"+-")){
        rules[i][j] = '+';
        rules[i+1][j] = '-';

        solveMagnets(rules,i,j+1);

        rules[i][j] = 'T';
        rules[i+1][j] = 'B';        
      }

      if(canPutPatternVertically(rules,i,j,"-+")){
        rules[i][j] = '-';
        rules[i+1][j] = '+';

        solveMagnets(rules,i,j+1);

        rules[i][j] = 'T';
        rules[i+1][j] = 'B';
      }

      if ((1 == 1) or canPutPatternVertically(rules,i,j,"xx")){
        rules[i][j] = 'x';
        rules[i+1][j] = 'x';

        solveMagnets(rules,i,j+1);

        rules[i][j] = 'T';
        rules[i+1][j] = 'B';           
      }

    }              
    else{
      solveMagnets(rules,i,j+1);
    }
  }
}


void doTheStuff(vector<vector<char>> &rules,int i,int j){

  if(rules[i][j] == 'L' || rules[i][j] == 'R'){
    if (canPutPatternHorizontally(rules, i, j ,"+-")){
      rules[i][j] = '+';
      rules[i][j+1] = '-';

      solveMagnets(rules,i,j);      
    }
  }
}

int main(){

  vector<vector<char>> rules = {
    {'L','R','L','R','T','T' },
    {'L','R','L','R','B','B' },
    {'T','T','T','T','L','R' },
    {'B','B','B','B','T','T' },
    {'L','R','L','R','B','B' }
  };
  solveMagnets(rules,0,0);

}
