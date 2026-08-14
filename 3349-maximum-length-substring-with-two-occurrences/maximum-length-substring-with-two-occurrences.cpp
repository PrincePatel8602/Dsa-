class Solution {
public:
    int maximumLengthSubstring(string s) {
        int n=s.size();
        unordered_map<char,int>mp;
        int l=0;
        int r=0;
        int ans=INT_MIN;
        while( r<n && l<=r){
           
            if(mp.count(s[r]) && mp[s[r]]>=2){
                mp[s[l]]--;
                l++;

            }else{
               mp[s[r]]++;
                r++;
                ans=max(ans,r-l);
            }
        }
        return ans;
    }
};