#include <bits/stdc++.h>
using namespace std;

string removeDuplicate(string s)
{
   // Used as index in the modified string
   int index = 0;   

   // Traverse through all characters
   for (int i = 0; i < s.size(); i++) {
       
     // Check if s[i] is present before it  
     int j;  
     for (j = 0; j < i; j++) 
        if (s[i] == s[j])
           break;
     
     // If not present, then add it to result
     if (j == i)
        s[index++] = s[i];
   }
   
   // Resize the string to remove extra characters
   s.resize(index);
   
   return s;
}

// Driver code
int main()
{
   string s = "geeksforgeeks";
   cout << removeDuplicate(s);
   return 0;
}