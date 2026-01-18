class Solution {
public:
    int largestMagicSquare(vector<vector<int>>& grid) {
        int m = grid.size(), n = grid[0].size();
        int ans = 1;

        for (int k = 2; k<= min(m, n); k++) {
            for (int i = 0; i + k <= m; i++) {
                for (int j=0; j+k<=n;j++){
                    int sum=0;
                    for (int x=0; x<k; x++)
                        sum+=grid[i][j+x];
                    bool ok=true;
                    for (int r=0; r<k; r++) {
                        int s=0;
                        for (int c=0; c<k; c++)
                            s+=grid[i+r][j+c];
                        if(s!=sum) ok=false;
                    }
                    for (int c=0; c<k; c++) {
                        int s=0;
                        for (int r=0;  r<k; r++)
                            s+=grid[i+r][j+c];
                        if(s!=sum) ok=false;
                    }

                    int d1=0, d2=0;
                    for (int x=0;x<k;x++) {
                        d1+=grid[i+x][j+x];
                        d2 += grid[i+x][j+k-1-x];
                    }

                    if (ok&&d1==sum&&d2==sum)
                        ans=k;
                }
            }
        }
        return ans;
    }
};
