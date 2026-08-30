class Solution {
public:
    int minimumDeletions(vector<int>& nums) {
        int maxp=INT_MIN;
        int imp=-1;
        int minp=INT_MAX;
        int ims=-1;
        int n=nums.size();
        for(int i=0;i<n;i++){
            if(nums[i]>maxp){
                maxp=nums[i];
                imp=i;
            }
            if(nums[i]<minp){
                minp=nums[i];
                ims=i;
            }
        }
        int maxb=n-imp;
        int minb=n-ims;
        int ans=INT_MAX;
        ans=min(ans,max(imp+1,ims+1));
        ans=min(ans,max(maxb,minb));
        int a=max(imp,ims);
        int b=min(imp,ims);
        ans=min(ans,n-a+b+1);
        return ans;


    }
};