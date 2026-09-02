class Solution {
public:
    int findMaxLength(vector<int>& nums) {
        unordered_map<int, int>mp{{0 ,-1}};
        int size=nums.size();
        int sum=0; 
        int result=0;
        for(int i=0; i<size; i++){
                if(nums[i] == 0){
                    sum--;
                }else{
                    sum++;
                }
          if(mp.count(sum)){
            result=max(result, i - mp[sum]);
          }else{
            mp[sum] = i;
          }
        }
          return result;
    }
};