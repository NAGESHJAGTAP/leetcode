class Solution {
public:
    int majorityElement(vector<int>& nums) {
        // int count=0;
        // int max=0;

        // for(int i=0; i<nums.size(); i++){
        //     if(count == 0){
        //         max=nums[i];
        //     }

        //     if(nums[i] == max){
        //         count++;
        //     }else{
        //         count--;
        //     }
        // }
        // return max;

        sort(nums.begin(), nums.end());
        int freq=1;
        int ans=nums[0];

        for(int i=1; i<nums.size(); i++){
            if(nums[i] == nums[i-1]){
                freq++;
            }else{
                freq=1;
                ans=nums[i];
            }
            if(freq > nums.size()/2){
                return ans;
            }
        }
        return ans;
    }
};