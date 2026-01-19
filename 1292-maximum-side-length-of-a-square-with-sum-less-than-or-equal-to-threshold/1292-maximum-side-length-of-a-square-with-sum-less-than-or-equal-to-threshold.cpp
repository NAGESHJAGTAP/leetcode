class Solution {
public:
    int maxSideLength(vector<vector<int>>& mat, int t) {
        int m = mat.size();
        int n = mat[0].size();
        int ans = 0;
        vector<vector<int>> p(m + 1, vector<int>(n+1,0));
        for (int i=0;i<m;i++)
            for (int j=0; j<n;j++)
                p[i+1][j+1]=mat[i][j]+p[i][j+1]+p[i+1][j]-p[i][j];

        for (int k = 1; k <= min(m, n); k++)
            for (int i = k; i <= m; i++)
                for (int j = k; j <= n; j++)
                    if (p[i][j] - p[i-k][j] - p[i][j-k] + p[i-k][j-k] <= t)
                        ans = k;

        return ans;
    }
};
