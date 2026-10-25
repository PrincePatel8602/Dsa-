class Solution {
public:
    int countMagicalPairs(string s) {
        int n=s.size();
        vector<vector<int>>co(n,vector<int>(n+1,0));
        for(int i=0;i<n;i++){
            unordered_map<char,int>mp;
            for(int j=i;j<n;j++){
                mp[s[j]]++;
                int np=mp.size();
                co[i][np]+=1;
            }
            
        }
        int ans=0;
        for(int i=0;i<n;i++){
            unordered_map<char,int>cp;
            for(int j=i;j<n;j++){
                cp[s[j]]++;
                int dp=cp.size();
                if(j+1<n){
                ans+=co[j+1][dp];
                }
            }
        }
        return ans;
    }
};