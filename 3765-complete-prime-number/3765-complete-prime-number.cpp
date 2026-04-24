class Solution {
public:
    bool isPrime(int n) {
        if (n < 2) return false;
        for (int i = 2; i <= n / 2; i++) {
            if (n % i == 0)
                return false;
        }
        return true;
    }

    bool completePrime(int num) {
        string s = to_string(num);
        int len = s.length();

        for (int i = 1; i <= len; i++) {
            int prefix = stoi(s.substr(0, i));
            int suffix = stoi(s.substr(len - i));

            if (!isPrime(prefix) || !isPrime(suffix))
                return false;
        }
        return true;
    }
};