class Solution {
public:
    long long minSumSquareDiff(vector<int>& nums1, vector<int>& nums2, int k1, int k2) {
        int n=nums1.size();
        unordered_map<int,int>mp;
        int a=INT_MIN;

        for(int i=0;i<n;i++){
          a=max(a,abs(nums1[i]-nums2[i]));
          int np=abs(nums1[i]-nums2[i]);
          mp[np]++;

        }
       for(int i=a-1;i>=0;i--){
        if(mp.find(i)==mp.end()){
            mp[i]=0;
        }
       }
       long long t=k1+k2;
       for(int i=a;i>0;i--){
        if(t>=mp[i]){
            mp[i-1]+=mp[i];
             t-=mp[i];
            mp[i]=0;
           
        }else{
            mp[i-1]+=t;
            mp[i]-=t;
            t=0;
            break;
        }
       }
       long long ans=0;
       for(auto it:mp){
        ans += (1LL * it.first * it.first * it.second);
       }
       return ans;
    }
};