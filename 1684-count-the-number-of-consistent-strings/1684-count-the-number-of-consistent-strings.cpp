class Solution {
public:
    int countConsistentStrings(string allowed, vector<string>& words) {
     int count = 0;

    for(string word:words) {
      bool isValid=true;
        for (char ch:word) {
            if (allowed.find(ch)==string::npos) {
                isValid=false;
                break;
            }
        }
        if(isValid)count++;
    }
    return count;
    }
};