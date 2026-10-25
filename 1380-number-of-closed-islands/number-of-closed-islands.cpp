class Solution {
public:
    int closedIsland(vector<vector<int>>& grid) {
        int m=grid.size();
        int n=grid[0].size();
        int row[4]={-1,0,1,0};
        int col[4]={0,-1,0,1};
        vector<vector<int>>vis(m,vector<int>(n,0));
        queue<pair<int,int>>q;
        for(int j=0;j<n;j++){
            if(grid[0][j]==0 && vis[0][j]==0){
               q.push({0,j});
               vis[0][j]=1;

            }
        }
        for(int j=0;j<n;j++){
            if(grid[m-1][j]==0 && vis[m-1][j]==0){
               q.push({m-1,j});
               vis[m-1][j]=1;

            }
        }
        for(int i=0;i<m;i++){
            if(grid[i][0]==0 && vis[i][0]==0){
               q.push({i,0});
               vis[i][0]=1;

            }
        }
        for(int i=0;i<m;i++){
            if(grid[i][n-1]==0 && vis[i][n-1]==0){
               q.push({i,n-1});
               vis[i][n-1]=1;

            }
        }
        while(!q.empty()){
            int ip=q.front().first;
            int jp=q.front().second;
            q.pop();
            for(int k=0;k<4;k++){
                int nr=ip+row[k];
                int nc=jp+col[k];
                if(nr<0 || nr>=m || nc<0 || nc>n-1){
                    continue;
                }
                if(grid[nr][nc]==0 && vis[nr][nc]==0){
                    q.push({nr,nc});
                    vis[nr][nc]=1;
                }
            }
        }
        
        int ans=0;
        for(int i=1;i<m-1;i++){
            for(int j=1;j<n-1;j++){
                if(grid[i][j]==0 && vis[i][j]==0){
                    q.push({i,j});
                    ans++;
                    vis[i][j]=1;
                }
              
            while(!q.empty()){
            int ip=q.front().first;
            int jp=q.front().second;
            q.pop();
            for(int k=0;k<4;k++){
                int nr=ip+row[k];
                int nc=jp+col[k];
                if(nr<0 || nr>=m || nc<0 || nc>n-1){
                    continue;
                }
                if(grid[nr][nc]==0 && vis[nr][nc]==0){
                    q.push({nr,nc});
                    vis[nr][nc]=1;
                }
            }
        }
      }
   }
        
         return ans;
    }
} ;