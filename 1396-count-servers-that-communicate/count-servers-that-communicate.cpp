class Solution {
public:
    int countServers(vector<vector<int>>& grid) {
        int m=grid.size();
        int n=grid[0].size();
        unordered_map<int,int>row;
        unordered_map<int,int>col;
        for(int i=0;i<m;i++){
            for(int j=0;j<n;j++){
                if(grid[i][j]==1){
                    row[i]++;
                    col[j]++;
                }
            }
        }
        int ans=0;
        for(int i=0;i<m;i++){
            for(int j=0;j<n;j++){
               if(grid[i][j]==1){
                   int np=row[i]+col[j];
                   if(np>2){
                    ans++;
                   }
               }
            }
        }
        return ans;
    }
};