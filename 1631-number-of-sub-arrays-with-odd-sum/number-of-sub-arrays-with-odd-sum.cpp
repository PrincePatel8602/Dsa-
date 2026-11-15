class Solution {
public:
    int numOfSubarrays(vector<int>& arr) {
        int MOD=1e9+7;
        int n=arr.size();
        int odd=0;
        int even=0;
        int sum=0;
        long long ans=0;
        for(int i=0;i<n;i++){
           sum+=arr[i];
           if(sum%2!=0){
            ans++;
           }
           if(sum%2==0){
            ans+=odd;
           }else{
            ans+=even;
           }
           if(sum%2==0){
            even++;
           }else{
            odd++;
           }
        }
        return ans%MOD;
    }
};