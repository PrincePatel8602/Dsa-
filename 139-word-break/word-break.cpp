class Solution {
public:
    vector<vector<int>>dp;
    unordered_map<string,int>mp;
    bool fun(int i,int j,string s){
        if(i>=s.size()){
            return true;
        }
        if(j>=s.size()){
            return false;
        }
        if(dp[i][j]!=-1){
            return dp[i][j];
        }
        string sp=s.substr(i,j-i+1);
        bool flag=fun(i,j+1,s);
        if(mp.count(sp)){
            flag=flag || fun(j+1,j+1,s); 
        }
        return dp[i][j]=flag;
    }
    bool wordBreak(string s, vector<string>& wordDict) {
        int np=wordDict.size();
        int n=s.size();
        dp.assign(n,vector<int>(n,-1));
        for(int i=0;i<np;i++){
            mp[wordDict[i]]++;
        }
        return fun(0,0,s);
    }
};