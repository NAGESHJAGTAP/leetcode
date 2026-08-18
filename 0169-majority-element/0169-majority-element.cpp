class Solution {
public:
    int majorityElement(vector<int>& nums) {
        
        int current=0;

        int majority=0;

        int n=nums.size();

        int freq=0;

        for(int i=0; i<n; i++){
            if(freq==0){
                current=nums[i];
                freq++;
            }

            else if(current == nums[i]){
                freq++;
            }
            else{
                freq--;
            }
        }

        return current;
    }
};