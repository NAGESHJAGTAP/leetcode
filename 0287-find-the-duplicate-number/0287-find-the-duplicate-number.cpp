class Solution {
public:
    int findDuplicate(vector<int>& nums) {
    //    sort(nums.begin(), nums.end());
    //    for(int i=0; i<nums.size(); i++){
    //     if(nums[i]==nums[i+1]){
    //         return nums[i];
    //     }
    //    } 
    //    return -1;
     
     unordered_map<int, int> mp;
     for(int i=0; i<nums.size(); i++){
        if(mp.count(nums[i])){
            return nums[i];
        }
        mp[nums[i]]=1;
     }
        return -1;

    }
};