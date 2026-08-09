class Solution {
public:
vector<vector<int>> dp;
    int fun(vector<int>&piles,int i,int M){
        int n=piles.size();
        if(i>=n){
            return 0;
        }
        if(dp[i][M]!=-1){
            return dp[i][M];
        }
        int take=0;
        int ans=INT_MIN;
         for (int k = 1; k <= 2 * M && i + k <= n; k++) {
            take += piles[i + k - 1];
            ans = max(ans, take - fun(piles, i + k, max(M, k)));
        }

        return dp[i][M] = ans;
    }
    int stoneGameII(vector<int>& piles) {
        int n=piles.size();
       dp.assign(n, vector<int>(n + 1, -1));
        int total = accumulate(piles.begin(), piles.end(), 0);
      int diff= fun(piles,0,1);
        return (total + diff) / 2;

    }
};