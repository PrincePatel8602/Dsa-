class Solution {
public:
    long long countCommas(long long n) {
        long long ans=0;
        long long num=1000;
        long long count=1;
        while(true){
           if(n<num){
               return ans;
           }
           if(n>=num && n<(long long)(num*1000)){
              ans+=(long long )(count*(n-num+1));
              return ans;
           }
           ans+=(long long)(count*(num*1000-num));
            count++;
           num*=1000;
        }
        return ans;
    }
};