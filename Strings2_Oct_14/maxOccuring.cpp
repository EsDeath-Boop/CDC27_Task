#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    char getMaxOccurringChar(string s) {
        sort(s.begin(), s.end());
        int maxFreq = 1, currFreq = 1;
        char maxChar = s[0];

        // Traverse the sorted string
        for (int i = 1; i < s.size(); i++) {
            // If same char, increase count
            if (s[i] == s[i - 1]) {
                currFreq++;
            } 
            else {
                // If frequency greater, update result
                if (currFreq > maxFreq) {
                    maxFreq = currFreq;
                    maxChar = s[i - 1];
                }
                currFreq = 1;
            }
        }

        // Final check for last character
        if (currFreq > maxFreq) {
            maxFreq = currFreq;
            maxChar = s[s.size() - 1];
        }

        // Return result
        return maxChar;
    }
};

int main() {
    // Input string
    string s = "samplestring";

    // Create object of Solution
    Solution obj;

    // Call function
    char ans = obj.getMaxOccurringChar(s);

    // Print result
    cout << "Max occurring character: " << ans << endl;
    return 0;
}