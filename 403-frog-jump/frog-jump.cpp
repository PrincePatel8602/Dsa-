class Solution {
public:
    vector<vector<int>>dp;
    bool fun(int prev,int curr, unordered_map<int,int>&mp,int n,vector<int>&stones){
        if(curr==n-1){
            return true;
        }
        if(dp[prev+1][curr]!=-1){
             return dp[prev+1][curr];
        }
        if(prev==-1){
            if(mp.count(stones[curr]+1)){
              return dp[prev+1][curr]=fun(curr,mp[stones[curr]+1],mp,n,stones);
            }
        }else{
            bool a=false;
            bool b=false;
            bool c=false;
            int cp=stones[curr]-stones[prev];
            if(cp-1>0 && mp.count(stones[curr]+cp-1)){
                 a=fun(curr,mp[stones[curr]+cp-1],mp,n,stones);
            }
            if(cp>0 && mp.count(stones[curr]+cp)){
                 b=fun(curr,mp[stones[curr]+cp],mp,n,stones);
            }
            if(cp+1>0 && mp.count(stones[curr]+cp+1)){
                 c=fun(curr,mp[stones[curr]+cp+1],mp,n,stones);
            }
           if(a || b|| c){
            return dp[prev+1][curr]=true;
           }

        }
            return dp[prev+1][curr]=false;


        }

    
    bool canCross(vector<int>& stones) {
        int n=stones.size();
        dp.assign(n+1,vector<int>(n,-1));
        unordered_map<int,int>mp;
        for(int i=0;i<n;i++){
            mp[stones[i]]=i;
        }
        return fun(-1,0,mp,n,stones);
    }
};