// class Solution {
// public:
//     int majorityElement(vector<int>& nums) {
//         int max=0; 
//         int count=0;
//         for(int i=0; i<nums.size(); i++){
//             if(count==0){
//                 max=nums[i];
//             }
//             if(nums[i]==max){
//                 count++;
//             }else{
//                 count--;
//             }
//         }
//         return max;
//     }
// };


class Solution {
public:
    int majorityElement(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        return nums[nums.size() / 2];
    }
};