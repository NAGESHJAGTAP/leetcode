class Solution {
public:
    string reverseByType(string s) {
       string a;
        string b;
        for(char c: s) (c >= 'a' && c<= 'z') ? a+=c : b+=c;
        reverse(a.begin(), a.end());
        reverse(b.begin(), b.end());
        int i=0;
        int j=0;
        for(char &c :s) (c>='a' && c<='z') ? c= a[i++] : c=b[j++];
        return s;
    }
};