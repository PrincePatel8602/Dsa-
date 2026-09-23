class Solution {
public:
    int minOperations(vector<int>& nums, int x) {
        int n=nums.size();
        unordered_map<int,int>pre;
        unordered_map<int,int>suff;
        int p=0;
        int s=0;
        for(int i=0;i<n;i++){
            p+=nums[i];
            pre[p]=i;
            s+=nums[n-1-i];
            suff[s]=i;
        }
        int np=INT_MAX;
        int cp=INT_MAX;
        int ans=INT_MAX;
        if(pre.find(x)!=pre.end()){
            np=pre[x]+1;
        }
        if(suff.find(x)!=suff.end()){
            cp=suff[x]+1;
        }
        ans=min(np,cp);
        
        for(auto it:pre){
            
           if(suff.find(x-it.first)!=suff.end()){
         
                ans=min(ans,it.second+suff[x-it.first]+2); 
                
           } 
        }
        if(ans==INT_MAX){
            return -1;
        }
        if(ans>n){
           return -1;
        }
        return ans;
    }
};