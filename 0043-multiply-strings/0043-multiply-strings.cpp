class Solution { 
public: 
    string multiply(string num1, string num2) { 
        if(num1 == "0" || num2 == "0"){ 
            return "0"; 
        } 
        
        int n = num1.length(); 
        int m = num2.length(); 
        vector<int> answer(n + m, 0); 
        
        for(int i = n - 1; i >= 0; i--){ 
            for(int j = m - 1; j >= 0; j--){ 
                int x = num1[i] - '0'; 
                int y = num2[j] - '0'; 
                
                int p = i + j + 1; 
                int sum = x * y + answer[p]; 
                answer[p] = sum % 10; 
                answer[p - 1] += sum / 10; 
            } 
        } 
        
        string result = ""; 
        int i = 0; 
        
        while(i < answer.size() && answer[i] == 0){ 
            i++; 
        } 
        
        while(i < answer.size()){ 
            result += (answer[i] + '0'); 
            i++; 
        } 
        
        return result; 
    } 
};
