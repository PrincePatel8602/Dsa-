class Solution {
public:
    long long maxAlternatingSum(vector<int>& nums) {
        int n=nums.size();
        sort(nums.begin(),nums.end());
        int i=0;
        int j=n-1;
        long long sum=0;
        int np=(n+1)/2;
        while(np--){
            long long f=1LL*nums[i]*nums[i];
            long long g=1LL*nums[j]*nums[j];
            if(f>g){
                sum+=f;
                i++;
            }else{
                sum+=g;
                j--;
            }
        }
        while(i<=j){
            long long h=1LL*nums[i]*nums[i];
            sum-=h;
            i++;
        }
        return sum;
    }
};