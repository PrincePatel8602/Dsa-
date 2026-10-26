class Solution {
public:
    int countIslands(vector<vector<int>>& grid, int k) {
        int m=grid.size();
        int n=grid[0].size();
        int row[4]={-1,0,1,0};
        int col[4]={0,1,0,-1};
        vector<vector<int>>vis(m,vector<int>(n,0));
        queue<pair<int,int>>q;
        int ans=0;
        for(int i=0;i<m;i++){
            for(int j=0;j<n;j++){
                
                if(grid[i][j]!=0 && vis[i][j]==0){
                    long long  sum=0;
                    q.push({i,j});
                    sum+=grid[i][j];
                    vis[i][j]=1;
                    while(!q.empty()){
                        int ip=q.front().first;
                        int jp=q.front().second;
                        q.pop();
                       for(int k=0;k<4;k++){
                        int nr=ip+row[k];
                        int nc=jp+col[k];
                        if(nr<0 || nr>=m || nc<0 || nc>=n){
                            continue;
                        }
                        if(grid[nr][nc]!=0 && vis[nr][nc]==0){
                              q.push({nr,nc});
                              vis[nr][nc]=1;
                              sum+=grid[nr][nc];
                        }
                       }
                    }
                    if(sum%k==0){
                        ans++;
                    }
                }

            }
        }
        return ans;
    }
};