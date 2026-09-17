class Solution {
public:
    bool validMountainArray(vector<int>& arr) {
        int size=arr.size();
        int i;
        if(size < 3){
            return false;
        }
        for(i=0; i<size; i++){
            if(arr[i] >= arr[i+1]){
              break;
            }
        }
        if(i == 0 || i==size-1){
            return false;
        }

        for(; i+1<size; i++){
            if(arr[i] <=arr[i+1]) {
                break;
            }
        }
         return i== size-1;
    }
};