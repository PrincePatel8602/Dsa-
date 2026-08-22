class Solution {
public:
    int minSubArrayLen(int target, vector<int>& nums) {
        int sum=0;
        int ans=INT_MAX;
        int l=0;
        int r=0;
        while(r<nums.size()){
            sum+=nums[r];
            r++;
           
                while(l<r){
                    if(sum>=target){
                        sum-=nums[l];
                        ans=min(r-l,ans);
                        l++;
                    }else{
                        break;
                    }
                    
                }
            }
            if(ans==INT_MAX){
               
                return 0;
            }
            return ans;
        
    }
};