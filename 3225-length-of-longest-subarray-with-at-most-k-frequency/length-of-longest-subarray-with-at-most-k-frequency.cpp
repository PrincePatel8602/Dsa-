class Solution {
public:
    int maxSubarrayLength(vector<int>& nums, int k) {
        int n=nums.size();
        unordered_map<int,int>mp;
        int l=0;
        int r=0;
        int ans=0;
        while(r<n && l<=r){
           if( mp.count(nums[r]) && mp[nums[r]]==k){
            mp[nums[l]]--;
            l++;
            

           }else{
            mp[nums[r]]++;
            r++;
            ans=max(ans,r-l);
           }
        }
return ans;
    }
};