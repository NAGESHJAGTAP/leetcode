class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        
        int currentSum=nums[0];

        int largestSum=nums[0];

        for(int i=1; i<nums.size(); i++){
            currentSum=max(nums[i], currentSum+nums[i]);
            largestSum=max(largestSum, currentSum);
        }

        return largestSum;
    }
};