class Solution {
public:
   
    string minWindow(string s, string t) {
        unordered_map<char,int>mp;
        unordered_map<char,int>prev;
        int ans=INT_MAX;
        int st=0;
        for(int i=0;i<t.size();i++){
            mp[t[i]]++;
            prev[t[i]]=1;
        }
        int l=0;
        int r=0;
        unordered_map<char,int>mpp;
        while(r<s.size()){
            if(prev[s[r]]){
             mpp[s[r]]++;
             }
             r++;
              bool flag=true;
             for(auto it:mp){
                if(!mpp.count(it.first) || mpp[it.first]<it.second){
                    flag=false;
                    break;
                }
             }
             if(flag==true){
           while(true && l<=r){
              if(prev[s[l]]==1){
                mpp[s[l]]--;
               
              }
              int cp=l;
              l++;
              if(mpp[s[cp]]<mp[s[cp]]){
                if((r-cp)<ans){
                    ans=r-cp;
                    st=cp;
                }
                break;
              }
           }
             }

           
        }
       if (ans == INT_MAX)
            return "";

        return s.substr(st, ans);
    }
};