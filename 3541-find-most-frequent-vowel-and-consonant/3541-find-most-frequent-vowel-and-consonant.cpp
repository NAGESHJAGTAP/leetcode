class Solution {
public:
    int maxFreqSum(string s) {
        int f[26] = {};
        int v = 0;
        int c = 0;
        for(char x : s) 
            f[x-'a']++;

        for(int i = 0; i < 26; i++) {
            if(string("aeiou").find('a' + i) != -1)
                v = max(v, f[i]);
            else
                c = max(c, f[i]);
        }
        return v + c;
    }
};