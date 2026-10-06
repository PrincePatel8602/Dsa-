class Solution {
public:
    bool dfs(vector<int>&flag,vector<vector<int>>&adj,int node){
        for(int j:adj[node]){
            if(flag[j]!=0 ){
            if(flag[j]==flag[node]){
                return false;
            }
            }else{
                if(flag[node]==1){
                    flag[j]=2;
                    dfs(flag,adj,j);
                }else{
                    flag[j]=1;
                    dfs(flag,adj,j);
                }
            }

            
        }
        return true;
    }
    bool possibleBipartition(int n, vector<vector<int>>& dislikes) {
    int np=dislikes.size();
      vector<vector<int>>adj(n+1);
      for(int i=0;i<np;i++){
        adj[dislikes[i][0]].push_back(dislikes[i][1]);
        adj[dislikes[i][1]].push_back(dislikes[i][0]);
      }
      vector<int>flag(n+1,0);
      
      for(int i=1;i<=n;i++){
        if(flag[i]==0){
            flag[i]=1;
        }
          if(!dfs(flag,adj,i)){
            return false;
          }
      }
      return true;
    }
};