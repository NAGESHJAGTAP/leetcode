class Solution {
public:
    int reverseDegree(string s) {
       int sum=0;
       for(int i=0; i<s.size(); i++){
        int reversePos = 'z' - s[i] + 1;
        int stringPos = i + 1;
         sum= sum+ reversePos * stringPos;
       } 
       return sum;
    }
};