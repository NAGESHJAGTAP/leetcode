class Solution {
public:
    string reversePrefix(string word, char ch) {
                int idx = 0; 
        string ans;
        for (int i = 0; i < word.size(); i++) {
            if (word[i] == ch) {
                idx += i; 
                break;
            }
        }
        for (int j = idx; j >= 0; j--) {
            ans += word[j];
        }
        for (int k = idx + 1; k < word.size(); k++) {
            ans += word[k];
        }
        return ans;
    }
};