class Solution {
public:
    vector<vector<vector<int>>>dp;
    bool  queue(vector<vector<char>>& grid,int np,int nc,int br){

        int m=grid.size();
        int n=grid[0].size();

        if(br<0){
            return 0;
        }
        if(np==m-1 && nc==n-1 && br==0){
            return dp[np][nc][br]=1;
        }
        else if(np==m-1 && nc==n-1 && br!=0){
            return dp[np][nc][br]=0;
        }

        
        if(dp[np][nc][br]!=-1){
            return dp[np][nc][br];
        }
        int nnp=np+1;
        int nnc=nc+1;

        bool check=true;

        if(nnp>=m && nnc<n){
          
            if(grid[np][nnc]=='('){
                check=queue(grid,np,nnc,br+1);
            }
            else{
                check=queue(grid,np,nnc,br-1);
            }
        }
        else if(nnc>=n && nnp<m){
           
            if(grid[nnp][nc]=='('){
                check=queue(grid,nnp,nc,br+1);
            }
            else{
                check=queue(grid,nnp,nc,br-1);
            }
        }
        else{
            
            int cpr=br;
            int dpr=br;

            if(grid[nnp][nc]=='('){
                cpr++;
            }
            else{
                cpr--;
            }

            if(grid[np][nnc]=='('){
                dpr++;
            }
            else{
                dpr--;
            }

            check=queue(grid,nnp,nc,cpr) ||
                  queue(grid,np,nnc,dpr);
        }

        return dp[np][nc][br]=check;
    }

    bool hasValidPath(vector<vector<char>>& grid) {
        int m=grid.size();
        int n=grid[0].size();
        dp.assign(m,vector<vector<int>>(n,vector<int>(n+m,-1)));

        if(grid[0][0]==')'){
            return false;
        }

        if(grid[m-1][n-1]=='('){
            return false;
        }

        return queue(grid,0,0,1);
    }
};