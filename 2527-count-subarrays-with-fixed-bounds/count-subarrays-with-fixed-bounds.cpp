
class Solution {
public:
    long long countSubarrays(vector<int>& nums, int minK, int maxK) {
        int n=nums.size();
        int gmax=-1;
        int gmin=-1;
        int gbad=-1;
        long long sum=0;
        for(int i=0;i<n;i++){
            if(nums[i]>maxK || nums[i]<minK){
                gbad=i;
            }else{
            if(nums[i]==minK){
                  gmin=i;
            }
             if(nums[i]==maxK){
                gmax=i;
            }
            }
            sum+=max(0,min(gmax,gmin)-gbad);
        }

        return sum;
    }
};