class Solution {
public:
    bool uniformArray(vector<int>& nums) {
        int n=nums.size();
        int odd=INT_MAX;
        int even=INT_MAX;
        for(int i=0;i<n;i++){
            if(nums[i]%2==0){
                even=min(nums[i],even);
            }else{
                odd=min(nums[i],odd);
            }
        }
        if(odd==INT_MAX && even!=INT_MAX){
            return true;
        }else if(odd!=INT_MAX && even==INT_MAX){
            return true;
        }else if(even>odd){
            return true;
        }
        return false;
    }
};

        