class Solution {
public:
    int minOperations(vector<int>& nums, int x) {
        int n=nums.size();
        vector<int>pre;
        unordered_map<int,int>suff;
        int p=0, s=0;
        int ans = INT_MAX;
        for(int i=0;i<n;i++){
            p+=nums[i];
            pre.push_back(p);
            s+=nums[n-1-i];
            suff[s]=i;
            if(p==x || s==x){
                ans = min(ans,i+1);
            }
        }

        for(int i=0; i<n; i++){
            int req = x-pre[i];
            if(suff.find(req) != suff.end()){
                int op = i+1+suff[req]+1;
                ans = min(ans,op);
            }
        }

        if(ans == INT_MAX){
            return -1;
        }
        if(ans>n){
            return -1;
        }
        return ans;
    }
};