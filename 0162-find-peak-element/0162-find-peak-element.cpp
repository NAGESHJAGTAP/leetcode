class Solution {
public:
    int findPeakElement(vector<int>& nums) {
        int size=nums.size();
        for(int i=0; i<size-1; i++){
            if(nums[i]>nums[i+1]){
                return i;
            }
        }
            return size-1;
    }
};