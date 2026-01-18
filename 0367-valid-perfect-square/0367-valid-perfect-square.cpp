class Solution {
public:
    bool isPerfectSquare(int num) {
         for (int i=1;num>0;i+=2)
            num=num-i;
        return num==0;
    }
};