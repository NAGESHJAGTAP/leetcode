class Solution {
public:
    long long minimumCost(string source, string target, vector<char>& original, vector<char>& changed, vector<int>& cost) {
         long long INF = 1e15;
        long long dist[26][26];

        // initialize
        for (int i = 0; i < 26; i++)
            for (int j = 0; j < 26; j++)
                dist[i][j] = (i == j) ? 0 : INF;

        // direct changes
        for (int i = 0; i < original.size(); i++) {
            dist[original[i] - 'a'][changed[i] - 'a'] =
                min(dist[original[i] - 'a'][changed[i] - 'a'],
                    (long long)cost[i]);
        }

        // floyd warshall
        for (int k = 0; k < 26; k++)
            for (int i = 0; i < 26; i++)
                for (int j = 0; j < 26; j++)
                    dist[i][j] = min(dist[i][j], dist[i][k] + dist[k][j]);

        // calculate answer
        long long ans = 0;
        for (int i = 0; i < source.size(); i++) {
            long long c = dist[source[i] - 'a'][target[i] - 'a'];
            if (c == INF) return -1;
            ans += c;
        }

        return ans;
    }
};