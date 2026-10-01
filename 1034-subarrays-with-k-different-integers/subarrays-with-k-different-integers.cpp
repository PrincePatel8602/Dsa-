class Solution {
public:
    int fun(vector<int>&nums,int kp){
        int n=nums.size();
        unordered_map<int,int>mp;
        int ans=0;
        int l=0;
        for(int i=0;i<n;i++){
            mp[nums[i]]++;
            if(mp.size()>kp){
                while(mp.size()>kp){
                    mp[nums[l]]--;
                    if(mp[nums[l]]==0){
                        mp.erase(nums[l]);
                        
                        
                    }
                    
                    l++;
                    
                }
            }
            ans+=(i-l+1);
        
            }
            return ans;
    }
    int subarraysWithKDistinct(vector<int>& nums, int k) {
        return fun(nums,k)-fun(nums,k-1);
        
    }
};