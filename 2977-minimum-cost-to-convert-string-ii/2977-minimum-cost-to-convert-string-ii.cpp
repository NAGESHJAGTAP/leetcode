class Solution {
public:
    long long minimumCost(string source, string target, vector<string>& original, vector<string>& changed, vector<int>& cost) {
        const long long INF = 1e18;
        int n = source.size();

        // Step 1: Collect all unique strings
        unordered_map<string, int> mp;
        int id = 0;
        for (auto &s : original)
            if (!mp.count(s)) mp[s] = id++;
        for (auto &s : changed)
            if (!mp.count(s)) mp[s] = id++;

        int m = id;
        vector<vector<long long>> dist(m, vector<long long>(m, INF));

        // cost to convert string to itself is 0
        for (int i = 0; i < m; i++)
            dist[i][i] = 0;

        // direct conversion costs
        for (int i = 0; i < original.size(); i++) {
            int u = mp[original[i]];
            int v = mp[changed[i]];
            dist[u][v] = min(dist[u][v], (long long)cost[i]);
        }

        // Step 2: Floyd–Warshall (simple triple loop)
        for (int k = 0; k < m; k++)
            for (int i = 0; i < m; i++)
                for (int j = 0; j < m; j++)
                    dist[i][j] = min(dist[i][j], dist[i][k] + dist[k][j]);

        // Step 3: DP
        vector<long long> dp(n + 1, INF);
        dp[0] = 0;

        for (int i = 0; i < n; i++) {
            if (dp[i] == INF) continue;

            // no cost if characters match
            if (source[i] == target[i])
                dp[i + 1] = min(dp[i + 1], dp[i]);

            // try all substrings
            for (auto &p : mp) {
                string s = p.first;
                int len = s.size();
                if (i + len > n) continue;

                if (source.substr(i, len) == s) {
                    string t = target.substr(i, len);
                    if (mp.count(t)) {
                        long long c = dist[mp[s]][mp[t]];
                        if (c < INF)
                            dp[i + len] = min(dp[i + len], dp[i] + c);
                    }
                }
            }
        }

        return dp[n] == INF ? -1 : dp[n];
    }
};