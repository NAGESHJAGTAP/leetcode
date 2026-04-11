class Solution {
public:
    string reverseWords(string s) {
        string word, ans;
        stringstream p(s);
        while (p >> word) {
            if (!ans.empty()){ 
              ans = word +" "+ ans;
            }else{ 
             ans = word;
            }
        }
        return ans;
    }
};
