class Solution {
public:
    vector<vector<int>>dp;
    int fun(string &s,string &t,int i,int j ){
        if(j==t.size()){
            return dp[i][j]=1;
        }
        if(i==s.size()){
            return dp[i][j]=0;
        }
        if(dp[i][j]!=-1){
            return dp[i][j];
        }
       int c=0;
        if(s[i]==t[j]){
          c+=fun(s,t,i+1,j+1);
        }
        c+=fun(s,t,i+1,j);
        return dp[i][j]=c;
    }
    int numDistinct(string s, string t) {
        int n=s.size();
        int m=t.size();
        dp.assign(n+1,vector<int>(m+1,-1));
        return fun(s,t,0,0);
    }
};