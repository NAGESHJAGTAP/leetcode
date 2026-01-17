class Solution {
public:
    bool isValid(string s) {
        stack<char>st;
        for(int i=0; i<s.size(); i++){
            int c=s[i];
          if (c == '(' || c == '{' || c == '['){
                 st.push(c);
            }else{
               if(st.empty()) return false;

             if ((c == ')' && st.top() != '(') ||
                (c == '}' && st.top() != '{') ||
                (c == ']' && st.top() != '['))
               return false;

               st.pop();
            }
        }
           return st.empty();
    }
};