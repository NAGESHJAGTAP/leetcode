class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
         unordered_map<string, int> mp;
         vector <vector<string>> result;

         for(int i=0; i<strs.size(); i++){
            string key=strs[i];

            sort(key.begin(), key.end());

            if(mp.find(key) == mp.end()){
                mp[key]=result.size();
                result.push_back({});
            }
            result[mp[key]].push_back(strs[i]);
         }
         return result;    
    }
};