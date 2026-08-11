class Solution {
public:
   bool fun(vector<vector<char>>& board,vector<vector<int>>&vis,string word,string mp,int i,int j){
    int n=board.size();
    int m=board[0].size();
   
    if(mp==word){
        return true;
    }
    if(i<0 || j<0 || j>=m || i>=n){
        return false;
    }

    if(vis[i][j]){
        return false;
    }
   
    if (mp.size() >= word.size()){
            return false;
        }
    if(board[i][j]!=word[mp.size()]){
        return false;
    }
     vis[i][j]=1;
    bool ans=(fun(board,vis,word,mp+board[i][j],i-1,j)||fun(board,vis,word,mp+board[i][j],i+1,j)|| fun(board,vis,word,mp+board[i][j],i,j-1) || fun(board,vis,word,mp+board[i][j],i,j+1));

    vis[i][j]=0;
    return ans;
   }
    bool exist(vector<vector<char>>& board, string word) {
        int n=board.size();
        int m=board[0].size();
        vector<vector<int>>vis(n,vector<int>(m,0));
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if( board[i][j]==word[0] &&fun(board,vis,word,"",i,j)){
                    return true;
                }
            }
        }
        return false;
    }
};