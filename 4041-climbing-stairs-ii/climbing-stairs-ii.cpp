
class Solution {
public:
vector<vector<int>>dp;
    int fun(vector<int>&costs,int i,int np){

       if(i>costs.size()){
        return INT_MAX;
       }
       if(i==costs.size()){
        return costs[i-1]+np*np;
       }
       if(np>0){
       if(dp[i][np]!=-1){
        return dp[i][np];
       }
       }
       int sum=0;

       if(np!=0){
        sum+=costs[i-1]+np*np;
       }

       int ans=INT_MAX;

       for(int s=1;s<=3;s++){
          ans=min(ans,fun(costs,i+s,s));
       }

       return dp[i][np]=sum+ans;
    }

    int climbStairs(int n, vector<int>& costs) {
        dp.assign(n+1,vector<int>(4,-1));
        return fun(costs,0,0);
    }
};
