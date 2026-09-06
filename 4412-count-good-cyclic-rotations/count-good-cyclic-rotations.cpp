class Solution {
public:
    int countGoodRotations(vector<int>& nums) {
        int n=nums.size();
        int ans=0;
        long long  pre=0;
        long long suff=0;
        for(int i=0;i<n;i++){
            if(i<n/2){
                pre+=nums[i];
            }else{
                suff+=nums[i];
            }
        }
        if(pre>suff){
            ans++;
        }
        for(int i=0;i<n-1;i++){
            pre-=nums[(i)%n];
            suff-=nums[(i+n/2)%n];
            suff+=nums[(i)%n];
            pre+=nums[(i+n/2)%n];
            if(pre>suff){
                ans++;
            }
        }
        return ans;

    }
};