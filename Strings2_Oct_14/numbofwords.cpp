#include <bits/stdc++.h>

using namespace std;

int main() {

  string str = "HI AMY AND JAY";
  int n = str.length();
  int spaces=0;
  
  for(int i=0; i<n; i++){
      if(str[i]==' ')
        spaces= spaces+1;
  }
  
  cout<<"The number of words are "<< spaces+1;

}