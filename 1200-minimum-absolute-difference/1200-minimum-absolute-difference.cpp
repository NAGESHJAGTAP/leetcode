class Solution {
public:
    vector<vector<int>> minimumAbsDifference(vector<int>& arr) {
        sort(arr.begin(), arr.end());
        vector<vector<int>> result;
        int minDiff=arr[1]-arr[0];

        for(int i=1;i<arr.size();i++) {
            int diff=arr[i]-arr[i-1];
            
            if (diff<minDiff){
                minDiff=diff;
                result.clear();
            }
            if(diff==minDiff) {
             result.push_back({arr[i-1],arr[i]});
            }
        }
        return result;
    }
};
