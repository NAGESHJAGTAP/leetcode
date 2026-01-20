class Solution {
public:
    vector<int> minBitwiseArray(vector<int>& nums) {
        vector<int> ans;
        ans.reserve(nums.size());
        for(int num : nums){
            if((num & 1) == 0){
                ans.push_back(-1);
                continue;
            }
             int lowbit = (num + 1) & -(num + 1);
             ans.push_back(num - (lowbit >> 1));
        }
        return ans;
    }
};