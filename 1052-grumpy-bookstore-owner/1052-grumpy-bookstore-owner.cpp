class Solution {
public:
    int maxSatisfied(vector<int>& customers, vector<int>& grumpy, int minutes) {
       int size=customers.size();
       int base=0;
       int val=0;
       int i;
       for(i=0; i<size; i++){
          if(grumpy[i] == 0){
            base=base + customers[i];
          }
       }
       int extraVal=0;
       for(i=0; i<minutes; i++){
        if(grumpy[i] == 1){
            val=val+customers[i];
        }
    };
        extraVal=val;
        for(i=minutes; i<size; i++){
        if(grumpy[i] == 1){
            val=val+customers[i];
        }
        if(grumpy[i - minutes] == 1){
            val=val - customers[i - minutes];
        }
        extraVal =  max(extraVal, val);
        }
    
    return base + extraVal;
         
    }
};