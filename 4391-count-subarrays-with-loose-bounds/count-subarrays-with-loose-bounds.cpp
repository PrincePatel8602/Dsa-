class Solution {
public:
    long long countSubarrays(vector<int>& nums, int minK, int maxK) {
        int n=nums.size();
        int l=0;
        int r=0;
        long long ans=0;
        for(int i=0;i<n;i++){
            if(nums[i]>=minK && nums[i]<=maxK){
                if(i-1>=0 && (nums[i-1]<minK || nums[i-1]>maxK)){
                    l=i;
                }
                r=i;
                ans+=(r-l+1);
            }else{
                 l=i;
                 r=i;
            }
        }
        return ans;
    }
};