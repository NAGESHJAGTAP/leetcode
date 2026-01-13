class Solution {
public:
    double separateSquares(vector<vector<int>>& squares) {
        double low = 1e9, high = 0;

        // find exact min & max possible y
        for (auto &s : squares) {
            low = min(low, (double)s[1]);
            high = max(high, (double)s[1] + s[2]);
        }
        for (int i = 0; i < 60; i++) {
            double mid = (low + high) / 2.0;
            double below = 0, above = 0;
            for (auto &s : squares) {
                double y = s[1];
                double l = s[2];
                if (mid <= y) {
                    above += l * l;
                } 
                else if (mid >= y + l) {
                    below += l * l;
                } 
                else {
                    below += (mid - y) * l;
                    above += (y + l - mid) * l;
                }
            }

            if (below < above)
                low = mid;
            else
                high = mid;
        }

        return low;
    }
};
