class Solution {
public:
    int dominantIndex(vector<int>& nums) {
        int firstLargest=INT_MIN;
        int secondLargest=INT_MIN;
        int index=-1;

        for(int i=0; i<nums.size(); i++){
            if(nums[i] > firstLargest){
                secondLargest=firstLargest;
                firstLargest=nums[i];
                index=i;
            }

             else if (nums[i]>secondLargest) {
                secondLargest = nums[i];
            }
        } 
        
         if(firstLargest >= 2*secondLargest) {
            return index;
        }

        return -1;
    }
};