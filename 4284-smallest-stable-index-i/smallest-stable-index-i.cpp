class Solution {
public:
    int firstStableIndex(vector<int>& nums, int k) {
        int n=nums.size();
        vector<int>pre(n);
        vector<int>suff(n);
        int maxp=INT_MIN;
        int minp=INT_MAX;
        for(int i=0;i<n;i++){
            maxp=max(maxp,nums[i]);
            pre[i]=maxp;
        }
        for(int i=n-1;i>=0;i--){
            minp=min(minp,nums[i]);
            suff[i]=minp;
        }
        int j=-1;
        for(int i=0;i<n;i++){
            if((pre[i]-suff[i])<=k){
                j=i;
                break;
            }
        }

        return j;
    }
};