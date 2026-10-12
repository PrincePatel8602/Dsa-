class Solution {
public:
    int MOD=1e9+7;
    int maxSum(vector<int>& nums, int k) {
        int n=nums.size();
        unordered_map<int,int>mp;
        for(int i=0;i<32;i++){
            mp[i]=0;
        }
        for(int i=0;i<n;i++){
           int ip=0;
            while(ip<32){
                int c=1<<ip;
                if(c&nums[i]){
                    mp[ip]++;
                }
                ip++;
            }
        }
        long long result=0;
        while(k--){
            long long curr=0;
            for(int i=0;i<32;i++){
                if(mp[i]>0){
                   mp[i]--;
                   curr=curr|(1<<i);
                }

            }
            result=(result+(curr*curr))%MOD;
        }
       return result;
    }
};