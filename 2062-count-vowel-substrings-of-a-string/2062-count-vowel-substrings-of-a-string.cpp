class Solution {
public:
    int countVowelSubstrings(string word) {
              int n = word.size(), ans = 0;
        
        for (int i = 0; i < n; i++) {
            int a=0;
            int e=0;
            int i1=0;
            int o=0;
            int u=0;
            
            for (int j = i; j < n; j++) {
                if (word[j]=='a') a=1;
                else if (word[j]=='e') e=1;
                else if (word[j]=='i') i1=1;
                else if (word[j]=='o') o=1;
                else if (word[j]=='u') u=1;
                else break;
                if (a && e && i1 && o && u) ans++;
            }
        }
        return ans;
    }
};