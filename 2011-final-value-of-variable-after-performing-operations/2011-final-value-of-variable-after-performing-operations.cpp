class Solution {
public:
    int finalValueAfterOperations(vector<string>& operations) {
    int X = 0;
        for (const string& operation : operations) {
            if (operation == "++X" || operation == "X++") {
                X=X+ 1;
            } else if (operation == "--X" || operation == "X--") {
                X=X- 1;
            }
        }
        return X;
    }
};