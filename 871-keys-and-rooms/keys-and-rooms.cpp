class Solution {
public:
    void dfs(vector<bool>&flag,vector<vector<int>>& rooms,int node){
        flag[node]=1;
        for(int i=0;i<rooms[node].size();i++){
            if(!flag[rooms[node][i]]){
                dfs(flag,rooms,rooms[node][i]);
            }
        }
    }
    bool canVisitAllRooms(vector<vector<int>>& rooms) {
        int n=rooms.size();
        vector<bool>flag(n,0);
        dfs(flag,rooms,0);
        for(int i=0;i<n;i++){
            if(flag[i]==0){
                return false;
            }
        }
        return true;
    }
};