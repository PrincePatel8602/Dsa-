class Solution {
public:
    long long maximizeSum(vector<int>& nums, int k) {
        int n=nums.size();
        vector<long long>mp;
        long long sum=0;
        for(int i=0;i<n;i++){
            sum+=nums[i];
        }
        for(int i=0;i<n;i++){
            vector<int>p(10,0);
            int np=nums[i];
            while(np>0){
                int d=np%10;
                p[d]+=1;
                np/=10;
            }
           
           long long dp=0;
            int ic=9;
            while(ic>=0){
                if(p[ic]==0){
                    ic--;
                    continue;
                }
                dp=1LL*dp*10+ic;
               
                p[ic]--;
          }
          mp.push_back({dp-nums[i]});

            
        }
        sort(mp.rbegin(),mp.rend());
       
        for(int i=0;i<k;i++){
            if(mp[i]>0){
                sum+=mp[i];
            }else{
                break;
            }
        }
        return sum;
    }
};