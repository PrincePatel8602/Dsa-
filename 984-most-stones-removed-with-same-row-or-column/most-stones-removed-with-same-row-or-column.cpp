class Solution {
public:
    void dfs(vector<bool>&flag,vector<vector<int>>&adj,int node){
           flag[node]=1;
           for(int j:adj[node]){
            if(!flag[j]){
                dfs(flag,adj,j);
            }
           }
    }
    int removeStones(vector<vector<int>>& stones) {
        int n=stones.size();
        vector<vector<int>>adj(n);
         for(int i=0;i<n;i++){
            for(int j=i+1;j<n;j++){
                if((stones[i][0]==stones[j][0])|| (stones[i][1]==stones[j][1])){
                    adj[i].push_back(j);
                     adj[j].push_back(i);
                }
            }
         }
         int ans=0;
        vector<bool>flag(n,0);
        for(int i=0;i<n;i++){
            if(flag[i]==0){
                ans++;
                dfs(flag,adj,i);
            }
          }
        
        return n-ans;
    }
};