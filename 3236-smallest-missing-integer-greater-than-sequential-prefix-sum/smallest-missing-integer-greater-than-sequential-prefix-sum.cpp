class Solution {
public:
    int missingInteger(vector<int>& nums) {
        
        int n=nums.size();
      
        unordered_map<int,int>mp;
        for(int i=0;i<n;i++){
            mp[nums[i]]++;
        }
       
        int sum=nums[0];
        for(int i=1;i<n;i++){
            if(nums[i]==nums[i-1]+1){
                sum+=nums[i];
            }else {
                break;
            }
        }
        int ans;
        int i=sum;
        while(true){
            if(!mp.count(i)){
                ans=i;
                break;
            }else{
                i++;
            }
        }
        return ans;
    }
};