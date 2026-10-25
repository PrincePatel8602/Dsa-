class Solution {
public:
    int countStaircase(vector<int>& nums) {
        int n=nums.size();
        int ans=0;
        for(int i=0;i<n;i++){
            unordered_map<int,pair<int,int>>mp;
            for(int j=i;j<n;j++){
                if(mp.find(nums[j])==mp.end()){
                    mp[nums[j]]={mp.size()+1,1};
                }else{
                    mp[nums[j]].second+=1;
                }
                bool ok=true;
               for(auto it:mp){
                if(it.second.first!=it.second.second){
                    ok=false;
                    break;
                }
               }
               if(ok){
                ans++;
               }
        
        }
        }
        return ans;
    }
};