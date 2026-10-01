class Solution {
public:
    vector<vector<vector<int>>> dp;
    int MOD = 1e9 + 7;

    int fun(int ind, int maxp, int cost, int n, int m, int k) {
        if (ind == n) {
            if (cost == k)
                return 1;
            return 0;
        }

        if (cost > k)
            return 0;

        if (dp[ind][maxp][cost] != -1) {
            return dp[ind][maxp][cost];
        }

        long long sum = 0;

        for (int i = 1; i <= m; i++) {
            if (maxp >= i) {
                sum += fun(ind + 1, maxp, cost, n, m, k);
            }
            else {
                sum += fun(ind + 1, i, cost + 1, n, m, k);
            }

            sum %= MOD;
        }

        return dp[ind][maxp][cost] = sum;
    }

    int numOfArrays(int n, int m, int k) {
        dp.assign(n, vector<vector<int>>(
            m + 1, vector<int>(k + 1, -1)
        ));

        return fun(0, 0, 0, n, m, k);
    }
};