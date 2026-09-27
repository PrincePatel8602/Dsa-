class Solution {
public:
    int maxSubarraySumCircular(vector<int>& nums) {
        int n=nums.size();
        int ans=INT_MIN;
        int sum=0;

        for(int i=0;i<n;i++){
           
           sum=max(nums[i],sum+nums[i]);
           ans=max(ans,sum);
        }
        int sump=0;
        int ansp=INT_MAX;
        for(int i=0;i<n;i++){
            sump=min(nums[i],sump+nums[i]);
            ansp=min(ansp,sump);
        }
        int as=0;
        for(int i=0;i<n;i++){
            as+=nums[i];
        }
        if(ansp<0){
            as-=ansp;
        }
        if(as==0){
            return ans;
        }
        return max(as,ans);
    }
};