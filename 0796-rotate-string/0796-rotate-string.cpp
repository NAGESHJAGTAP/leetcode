class Solution {
public:
    bool rotateString(string s, string goal) {
    if(s.size() != goal.size()) return false;
    
        string dou =s+s;
        return dou.find(goal) != -1;
    }
};