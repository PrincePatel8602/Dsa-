class Solution {
public:
    int distinctSubseqII(string s) {
        int n=s.size();
        const int MOD=1e9+7;
        vector<int>dp(n+1,0);
        dp[0]=1;
        vector<int>last(26,-1);
        for(int i=0;i<n;i++){
            int np=s[i]-'a';
            dp[i+1]=(dp[i]*2)%MOD;
            if(last[np]>=0){
                dp[i+1]-=dp[last[np]];
                dp[i+1]%=MOD;

            }
            last[np]=i;
        }
    dp[n]--;
    if(dp[n]<0){
        dp[n]+=MOD;
    }
    return dp[n];

    }
};