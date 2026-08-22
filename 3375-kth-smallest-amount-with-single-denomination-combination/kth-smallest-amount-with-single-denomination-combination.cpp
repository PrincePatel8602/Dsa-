class Solution {
public:
    long long countsmaller(long long mid,vector<int>&coins){
        long long ans=0;
        int n=coins.size();
        for(long long  e=1;e<(1<<n);e++){
            long long order=0;
            long long lcm=0;
            for(int i=0;i<n;i++){
                if(e &(1LL<<i)){
                    order++;
                    if(lcm==0){
                        lcm=coins[i];
                    }else{
                        lcm=(lcm*coins[i])/(gcd(lcm,coins[i]));
                    }
                }
            }
            if(order%2==0){
                ans-=mid/lcm;
            }else{
                ans+=mid/lcm;
            }
            
        }
         return ans;
    }
   
    long long findKthSmallest(vector<int>& coins, int k) {
        long long res=-1;
        long long l=1;
        long long h=(long long )(*max_element(coins.begin(),coins.end()))*k;
        while(l<=h){
            long long mid=l+(h-l)/2;
            if(countsmaller(mid,coins)>=k){
                res=mid;
                h=mid-1;

            }else{
                l=mid+1;
            }
        }
        return res;
     }
};