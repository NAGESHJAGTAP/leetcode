class Solution {
public:
    vector<int> minBitwiseArray(vector<int>& nums) {
        vector<int>arr;
        for(int i = 0 ; i <nums.size();i++){
        bool found = false;
            for(int j = 1; j<nums[i] ;j++){
                if( (j  |  (j+1)) == nums[i]){
                    arr.push_back(j);
                    found = true;
                    break;
                }
            }
        if(!found){
            arr.push_back(-1);
        }
        }
        return arr;
        
    }
};
