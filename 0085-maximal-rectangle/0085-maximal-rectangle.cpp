class Solution {
public:
    int maximalRectangle(vector<vector<char>>& matrix) {
        if (matrix.empty()) return 0;

        int rows = matrix.size(), cols = matrix[0].size();
        vector<int> h(cols, 0);
        int ans = 0;

        for (int i = 0; i < rows; i++) {
            for (int j = 0; j < cols; j++) {
                if (matrix[i][j] == '1') h[j]++;
                else h[j] = 0;
            }

            stack<int> st;
            for (int j = 0; j <= cols; j++) {
                int cur = (j == cols) ? 0 : h[j];
                while (!st.empty() && cur < h[st.top()]) {
                    int height = h[st.top()];
                    st.pop();
                    int width = st.empty() ? j : j - st.top() - 1;
                    ans = max(ans, height * width);
                }
                st.push(j);
            }
        }
        return ans;
    }
};
