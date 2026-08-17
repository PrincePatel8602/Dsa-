class Solution {
public:
vector<int>pre;
vector<vector<int>>dp;
    int fun(vector<int>&stoneValue,int l,int r){
        if(l>=r){
            return 0;
        }
        if(dp[l][r]!=-1){
            return dp[l][r];
        }
        int leftsum=0;
        int rightsum=pre[r+1]-pre[l];
        int ans=INT_MIN;
        for(int i=l;i<r;i++){
            leftsum+=stoneValue[i];
            rightsum-=stoneValue[i];
            if(leftsum<rightsum){
                ans=max(ans,leftsum+fun(stoneValue,l,i));
            }else if(leftsum>rightsum){
                ans=max(ans,rightsum+fun(stoneValue,i+1,r));
            }else{
                ans=max({ans,leftsum+fun(stoneValue,l,i),rightsum+fun(stoneValue,i+1,r)});
            }
        }
        return dp[l][r]=ans;
    }
    int stoneGameV(vector<int>& stoneValue) {
        int n=stoneValue.size();
        dp.assign(n,vector<int>(n,-1));
        int sum=0;
        pre.assign(n+1,0);
        pre[0]=sum;
for (int i = 0; i < n; i++) {
            pre[i + 1] = pre[i] + stoneValue[i];
        }

        return fun(stoneValue,0,n-1);
    }
};