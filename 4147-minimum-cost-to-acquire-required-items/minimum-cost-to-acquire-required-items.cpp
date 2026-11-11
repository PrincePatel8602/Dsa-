class Solution {
public:
    long long minimumCost(int cost1, int cost2, int costBoth, int need1, int need2) {
      long long a=LLONG_MAX;
      long long  b=LLONG_MAX;
      long long c=LLONG_MAX;
      int co=max(need1,need2);
      a=1LL*co*costBoth;
       if(need1>=need2){
        b=1LL*need2*costBoth;
        b+=1LL*(need1-need2)*cost1;
       }else{
         b=1LL*need1*costBoth;
        b+=1LL*(need2-need1)*cost2;
       }
       c=1LL*cost1*need1+1LL*cost2*need2;
       return min({a,b,c});
    }
};