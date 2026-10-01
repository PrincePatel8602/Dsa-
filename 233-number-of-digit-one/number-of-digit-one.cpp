class Solution {
public:
    vector<vector<vector<int>>>dp;
    int fun(int idx,int tight,int count,string s){
        if(idx==s.size()){
            
          return count;
        }
        if(dp[idx][tight][count]!=-1){
            return dp[idx][tight][count];
        }
        int up;
        if(tight==0){
            up=9;
        }else{
            up=(s[idx]-'0');
        }
        int ans=0;
        for(int i=0;i<=up;i++){
            if(tight && i==(s[idx]-'0')){
                if(i==1){
                ans+=fun(idx+1,1,count+1,s);
                }else{
                    ans+=fun(idx+1,1,count,s);
                }
            }else{
                if(i==1){
                ans+=fun(idx+1,0,count+1,s);
                }else{
                 ans+=fun(idx+1,0,count,s);
                }
            }
        }
        return  dp[idx][tight][count]=ans;
    }
    int countDigitOne(int n) {
        string s=to_string(n);
        int np=s.size();
        dp.assign(np,vector<vector<int>>(2,vector<int>(np,-1)));
        return fun(0,1,0,s);
    }
};