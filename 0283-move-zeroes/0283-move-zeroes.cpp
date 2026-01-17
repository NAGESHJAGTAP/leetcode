class Solution {
public:
    void moveZeroes(vector<int>& nums) {
        // int pos=0;
        // for(int i=0; i<nums.size(); i++){
        //     if(nums[i] != 0){
        //      nums[pos]=nums[i];
        //      pos++;
        //     }
        // }
        // for(int i=pos; i<nums.size(); i++){
        //     nums[i] = 0;
        // }




        // int pos=0;
        // for(int i=0; i<nums.size(); i++){
        //     if(nums[i] != 0){
        //         swap(nums[pos], nums[i]);
        //         pos++;
        //     }
        // }



     int k=0;
     for(int i=0; i<nums.size(); i++){
        if(nums[i] != 0){
            swap(nums[k], nums[i]);
             k++;
        }
     }     



    }
};