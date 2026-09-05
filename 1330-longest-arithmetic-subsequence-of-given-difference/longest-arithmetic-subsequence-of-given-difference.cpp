class Solution {
public:
   

    int longestSubsequence(vector<int>& arr, int difference) {
        int n=arr.size();
        int k=difference;
        unordered_map<int,int>mp;
        int ans=1;
        for(int i=0;i<n;i++){
            if(mp.count(arr[i]-k)){
                mp[arr[i]]=1+mp[arr[i]-k];
                ans=max(ans,mp[arr[i]]);
            }else{
            mp[arr[i]]=1;
            }
        }
        return ans;
    }
};