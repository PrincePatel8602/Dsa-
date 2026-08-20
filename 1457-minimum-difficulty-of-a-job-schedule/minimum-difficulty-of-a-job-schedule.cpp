class Solution {
public:
    vector<vector<int>> dp;

    int fun(int i, int d, vector<int>& jobs) {
        int n = jobs.size();

        if (d == 0) {
            return (i == n ? 0 : 1e9);
        }

        if (n - i < d) {
            return 1e9;
        }

        if (dp[i][d] != -1) {
            return dp[i][d];
        }

        int ans = 1e9;
        int maxp = 0;

       
        for (int j = i; j <= n - d; j++) {

            maxp = max(maxp, jobs[j]);

            int next = fun(j + 1, d - 1, jobs);

            ans = min(ans, maxp + next);
        }

        return dp[i][d] = ans;
    }

    int minDifficulty(vector<int>& jobDifficulty, int d) {
        int n = jobDifficulty.size();

        if (n < d)
            return -1;

        dp.assign(n, vector<int>(d + 1, -1));

        return fun(0, d, jobDifficulty);
    }
};