class Solution {
public:
    bool hasValidPath(vector<vector<char>>& grid) {
        int m=grid.size();
        int n=grid[0].size();
        if(grid[0][0]==')'){
            return false;
        }
        if(grid[m-1][n-1]=='('){
            return false;
        }
        vector<vector<vector<int>>>dp(m,vector<vector<int>>(n,vector<int>(m+n,0)));
        dp[0][0][1]=1;
        for(int i=0;i<m;i++){
            for(int j=0;j<n;j++){
                 if(i == 0 && j == 0){
                    continue;
                }
                for(int br=0;br<m+n;br++){
                    int prev;
                    if(grid[i][j]==')'){
                       prev=br+1;
                    }else{
                        prev=br-1;
                    }
                    if(prev < 0 || prev >= m+n) continue;
                    if(i>0 && dp[i-1][j][prev]){
                        dp[i][j][br]=1;
                    }
                    if(j>0 && dp[i][j-1][prev]){
                        dp[i][j][br]=1;
                    }
                }
            }
        }
        return dp[m-1][n-1][0];
    }
};