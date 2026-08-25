class Solution {
public:
    int missingMultiple(vector<int>& nums, int k) {
        int n=nums.size();
        unordered_map<int,int>mp;
        for(int i=0;i<n;i++){
            mp[nums[i]]++;
        }
        int ip=1;
        while(true){
            if(!mp.count(k*ip)){
                return k*ip;
            }
            ip++;
        }
        return 0;
    }
};