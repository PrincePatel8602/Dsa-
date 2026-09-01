class Solution {
public:
    int minMoves(vector<string>& classroom, int energy) {
        int dx[4] = {0, 1, 0, -1};
        int dy[4] = {1, 0, -1, 0};
        int m=classroom.size();
        int n=classroom[0].size();
        vector<string>c=classroom;
        int sr=-1;
        int sc=-1;
        int cnt=0;
        vector<vector<int>>id(m,vector<int>(n,0));
        for(int i=0;i<m;i++){
            for(int j=0;j<n;j++){
             if(c[i][j]=='S'){
                sr=i;
                sc=j;
             }else if(c[i][j]=='L'){
                id[i][j]=1<<cnt++;
             }
            }
        }
        vector best(m,vector(n,vector<int>(1<<cnt,-1)));
        best[sr][sc][0]=energy;
        struct info{
            int x,y,mask,e,steps;
        };
        queue<info>q;
        q.push({sr,sc,0,energy,0});
        while(!q.empty()){
            info t=q.front();
            q.pop();
            if(t.mask==(1<<cnt)-1){
                return t.steps;
            }
            if(t.e==0){
                continue;
            }
            for(int i=0;i<4;i++){
                int nx=t.x+dx[i];
                int ny=t.y+dy[i];
                if(nx<0 || nx>=m || ny<0 || ny>=n || c[nx][ny]=='X'){
                    continue;
                }
                int ne=c[nx][ny]=='R'?energy:t.e-1;
                int nmask=t.mask|id[nx][ny];
                if(ne>best[nx][ny][nmask]){
                    best[nx][ny][nmask]=ne;
                    q.push({nx,ny,nmask,ne,t.steps+1});
                }
            }
        }
        return -1;
    }
};