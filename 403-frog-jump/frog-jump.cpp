class Solution {
public:
    vector<vector<int>>dp;
    // bool fun(int prev,int curr, unordered_map<int,int>&mp,int n,vector<int>&stones){
    //     if(curr==n-1){
    //         return true;
    //     }
    //     if(dp[prev+1][curr]!=-1){
    //          return dp[prev+1][curr];
    //     }
    //     if(prev==-1){
    //         if(mp.count(stones[curr]+1)){
    //           return dp[prev+1][curr]=fun(curr,mp[stones[curr]+1],mp,n,stones);
    //         }
    //     }else{
    //         bool a=false;
    //         bool b=false;
    //         bool c=false;
    //         int cp=stones[curr]-stones[prev];
    //         if(cp-1>0 && mp.count(stones[curr]+cp-1)){
    //              a=fun(curr,mp[stones[curr]+cp-1],mp,n,stones);
    //         }
    //         if(cp>0 && mp.count(stones[curr]+cp)){
    //              b=fun(curr,mp[stones[curr]+cp],mp,n,stones);
    //         }
    //         if(cp+1>0 && mp.count(stones[curr]+cp+1)){
    //              c=fun(curr,mp[stones[curr]+cp+1],mp,n,stones);
    //         }
    //        if(a || b|| c){
    //         return dp[prev+1][curr]=true;
    //        }

    //     }
    //         return dp[prev+1][curr]=false;


    //     }

    
    bool canCross(vector<int>& stones) {
        int n=stones.size();
        dp.assign(n+1,vector<int>(n,0));
        unordered_map<int,int>mp;
        for(int i=0;i<n;i++){
            mp[stones[i]]=i;
        }
       for(int i=0;i<n;i++){
    dp[i][n-1]=1;
}
        for(int curr=n-2;curr>=0;curr--){
            for(int prev=curr-1;prev>=-1;prev--){
                if(prev==-1){
                     if (mp.count(stones[curr] + 1)) {
                        int next = mp[stones[curr] + 1];

                        dp[prev + 1][curr] = dp[curr + 1][next];
                    }
                }else{
                    int diff=stones[curr]-stones[prev];
                    if(diff-1>0 && mp.count(stones[curr]+diff-1)){
                        if(dp[curr+1][mp[stones[curr]+diff-1]]){
                            dp[prev+1][curr]=1;
                            continue;
                        }

                    }
                    if(diff>0 && mp.count(stones[curr]+diff)){
                        if(dp[curr+1][mp[stones[curr]+diff]]){
                            dp[prev+1][curr]=1;
                            continue;
                        }
                        
                    }
                    if(diff+1>0 && mp.count(stones[curr]+diff+1)){
                        if(dp[curr+1][mp[stones[curr]+diff+1]]){
                            dp[prev+1][curr]=1;
                            continue;
                        }
                        
                    }
                }
            }
        }
        return dp[0][0];
    }
};