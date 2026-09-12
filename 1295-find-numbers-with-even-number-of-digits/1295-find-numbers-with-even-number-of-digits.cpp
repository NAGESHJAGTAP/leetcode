class Solution {
public:
    int findNumbers(vector<int>& nums) {
       int count=0;
       for(int num : nums){
        int degits=to_string(num).length();

        if(degits % 2 == 0){
            count++;
        }
       } 
       return count;
    }
};