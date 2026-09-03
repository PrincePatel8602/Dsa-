class Solution {
public:
    int dr[4]={-1,0,1,0};
    int dc[4]={0,-1,0,1};
   
    vector<vector<int>> pacificAtlantic(vector<vector<int>>& heights) {
        int m=heights.size();
        int n=heights[0].size();
        vector<vector<bool>>po(m,vector<bool>(n,0));
        queue<pair<int,int>>q;
        vector<vector<int>>vis(m,vector<int>(n,0));
        for(int i=0;i<n;i++){
            q.push({0,i});
            vis[0][i]=1;
            po[0][i]=1;
        }
        for(int j=1;j<m;j++){
            q.push({j,0});
            vis[j][0]=1;
            po[j][0]=1;
        }
        while(!q.empty()){
            int r=q.front().first;
            int c=q.front().second;
            q.pop();
            for(int i=0;i<4;i++){
                int nr=r+dr[i];
                int nc=c+dc[i];
                if(nr<0 || nc<0 || nr>=m || nc>=n || vis[nr][nc]==1 || heights[r][c]>heights[nr][nc]){
                    continue;
                }
                q.push({nr,nc});
                vis[nr][nc]=1;
                po[nr][nc]=1;

            }
        }
        vector<vector<bool>>ao(m,vector<bool>(n,0));
        queue<pair<int,int>>qp;
        vector<vector<int>>visp(m,vector<int>(n,0));
        for(int i=0;i<n;i++){
            qp.push({m-1,i});
            visp[m-1][i]=1;
            ao[m-1][i]=1;
        }
        for(int j=0;j<m-1;j++){
            qp.push({j,n-1});
            visp[j][n-1]=1;
            ao[j][n-1]=1;
        }
        while(!qp.empty()){
            int r=qp.front().first;
            int c=qp.front().second;
            qp.pop();
            for(int i=0;i<4;i++){
                int nr=r+dr[i];
                int nc=c+dc[i];
                if(nr<0 || nc<0 || nr>=m || nc>=n || visp[nr][nc]==1 || heights[r][c]>heights[nr][nc]){
                    continue;
                }
                qp.push({nr,nc});
                visp[nr][nc]=1;
                ao[nr][nc]=1;

            }
        }
        vector<vector<int>>ans;
        for(int i=0;i<m;i++){
            for(int j=0;j<n;j++){
               if(po[i][j]==1 && ao[i][j]==1){
                ans.push_back({i,j});
               }
            }
        }
        return ans;
    }
};