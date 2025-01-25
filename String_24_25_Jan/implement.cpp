class Solution {
public:
    int strStr(string haystack, string needle) {
        if (needle.empty()) {
        return 0;
    }
    
    int haystack_len = haystack.size();
    int needle_len = needle.size();
    
    for (int i = 0; i <= haystack_len - needle_len; i++) {
        bool match = true;
        for (int j = 0; j < needle_len; j++) {
            if (haystack[i + j] != needle[j]) {
                match = false;
                break;
            }
        }
        if (match) {
            return i;
        }
    }
    return -1;
    }
};