class Solution {
public:
    int minimumSumSubarray(vector<int>& nums, int l, int r) {
        int ans=INT_MAX;
       int n=nums.size();
       for(int i=0;i<n;i++){
             int sum=0;
        for(int j=i;j<n && j<=i+r-1;j++){
               sum+=nums[j];
               if(sum>0 && (j-i+1)>=l){
                ans=min(ans,sum);
               }
        }
       }
       if(ans==INT_MAX){
        return -1;
       }
       return ans;
    }
};