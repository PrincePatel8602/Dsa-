class Solution {
public:
    vector<vector<int>> colorGrid(int n, int m, vector<vector<int>>& sources) {
       vector<vector<int>>source(n,vector<int>(m,0));
       for(int i=0;i<sources.size();i++){
        int r=sources[i][0];
        int c=sources[i][1];
        int col=sources[i][2];
        source[r][c]=col;
       }
        int dr[4]={-1,0,1,0};
        int dc[4]={0,-1,0,1};
        vector<vector<int>>t(n,vector<int>(m,0));
        queue<pair<int,int>>q;
        for(int i=0;i<n;i++){
           for(int j=0;j<m;j++){
            if(source[i][j]!=0){
                q.push({i,j});
            }
           }
        }
        while(!q.empty()){
            int r=q.front().first;
            int c=q.front().second;
            q.pop();
            for(int i=0;i<4;i++){
                int nr=r+dr[i];
                int nc=c+dc[i];
                if(nr<0 || nc<0 || nr>=n || nc>=m){
                    continue;
                }
                if(source[nr][nc]==0){
                    q.push({nr,nc});
                    source[nr][nc]=source[r][c];
                    t[nr][nc]=t[r][c]+1;
                }
                if((source[nr][nc]!=0) && (t[nr][nc]==t[r][c]+1)&& (source[r][c]>source[nr][nc])){
                    source[nr][nc]=source[r][c];
                   
                }
            }

        }
        return source;
    }
};