class Solution {
public:
    string convertToBase7(int num) {
        if(num==0) return "0";
        bool negative=num<0;
        num=abs(num);
        string result="";
        while(num>0){
            result=char('0' + (num%7))+result;
            num/=7;
        }

        if (negative) result="-"+result;
        return result;
    }
};