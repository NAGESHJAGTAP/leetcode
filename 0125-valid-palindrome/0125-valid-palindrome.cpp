class Solution {
public:
    bool isPalindrome(string s) {
        string clean = "";
        for (int i = 0; i < s.size(); i++) {
            if (isalnum(s[i])) {   
                clean += tolower(s[i]);
            }
        }
        int start = 0;
        int end = clean.size() - 1;
        while (start < end) {
            if (clean[start] != clean[end]) {
                return false; 
            }
            start++;
            end--;
        }
        return true; 
    }
};