class Solution {
public:
    int passThePillow(int n, int time) {
        int t=time%(2*(n-1));
        if (t<n){  
            return 1+t;
        }
        return 2*n-t-1;
    }
};