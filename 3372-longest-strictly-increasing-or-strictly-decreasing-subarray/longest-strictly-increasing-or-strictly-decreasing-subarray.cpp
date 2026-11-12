
class Solution {
public:
    int longestMonotonicSubarray(vector<int>& nums) {
        int i=0;
        int j=0;
        int inc=0;
        int dec=0;
        int n=nums.size();
        int ans=1;

        while(j<n-1){
            if(inc==1){
                if(nums[j+1]>nums[j]){
                    j++;
                    ans=max(ans,j-i+1);
                }else{
                    inc=0;
                    i=j;
                    if(nums[j+1]<nums[j]){
                        dec=1;
                    }
                    j++;
                    ans=max(ans,j-i+1);
                }
            }
            else if(dec==1){
                if(nums[j+1]<nums[j]){
                    j++;
                    ans=max(ans,j-i+1);
                }else{
                    dec=0;
                    i=j;
                    if(nums[j+1]>nums[j]){
                        inc=1;
                    }
                    j++;
                    ans=max(ans,j-i+1);
                }
            }
            else {
                if(nums[j+1]>nums[j]){
                    i=j;
                    inc=1;
                    j++;
                    ans=max(ans,2);
                }
                else if(nums[j+1]<nums[j]){
                    i=j;
                    dec=1;
                    j++;
                    ans=max(ans,2);
                }
                else{
                    j++;
                    i=j;
                }
            }
        }

        return ans;
    }
};
