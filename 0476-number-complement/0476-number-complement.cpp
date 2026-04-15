class Solution {
public:
    int findComplement(int m) {
    int mask = 0;
    int n = m; 
      while (n != 0) {
    mask = (mask << 1) | 1; 
     n = n >> 1; 
     }
     int ans = (~m) & mask;
      return ans;
    }
};
