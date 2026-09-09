class Solution {
public:
    int maxProduct(vector<int>& nums) {
        int size=nums.size();
        int largest=nums[0];
  
       for(int i=0; i<size; i++){
        int product=1;
        for(int j=i; j<size; j++){
           product=product*nums[j]; 
        
        largest= max(largest,product);
        }
       }
  return largest;
    }
};