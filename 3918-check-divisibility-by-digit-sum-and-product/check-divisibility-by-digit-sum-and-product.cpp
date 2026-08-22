class Solution {
public:
    bool checkDivisibility(int n) {
        int sum=0;
        long long pro=1;
        int s=n;
        while(n>0){
            int d=n%10;
            sum+=d;
            pro*=d;
            n/=10;

        }
        int total=sum+pro;
        if(s%total==0){
            return true;
        }
         return false;
    }
};