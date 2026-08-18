class Solution {
public:
    unordered_map<string,int>mp;
    vector<string>ans;
    void fun(int i,int j,string sp,string s){
        int n=s.size();
        if(i>=n){
            int sc=sp.size();
            string kp=sp.substr(0,sc-1);
           

            ans.push_back(kp);
            return ;

        }
        if(j>=n){
            return ;
        }
          fun(i,j+1,sp,s);
        if(mp.count(s.substr(i,j-i+1))){
          
            fun(j+1,j+1,sp+s.substr(i,j-i+1)+" ",s);
        }
      
    }
    vector<string> wordBreak(string s, vector<string>& wordDict) {
        int np=wordDict.size();
        for(int i=0;i<np;i++){
            mp[wordDict[i]]++;
        }
         fun(0,0,"",s);
         return ans;
    }
};