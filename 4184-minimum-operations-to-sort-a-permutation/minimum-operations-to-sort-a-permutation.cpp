class Solution {
public:
    int minOperations(vector<int>& nums) {
        int n=nums.size();
        bool flag=true;
        for(int i=0;i<n;i++){
            if(nums[i]!=i){
                flag=false;
                break;
            }
        }
        bool ok=true;
        for(int i=0;i<n;i++){
            if(nums[i]!=(n-1-i)){
                ok=false;
                break;
            }
        }
        if(flag){
            return 0;
        }
        if(ok){
            return 1;
        }
        int maxp=-1;
        int minp=-1;
        for(int i=0;i<n;i++){
            if(nums[i]==0){
                minp=i;
            }else if(nums[i]==n-1){
                maxp=i;
            }
        }
        if(abs(maxp-minp)!=1){
            return -1;
        }
       
        if(minp<maxp){
                for(int j=1;j<=minp;j++){
                    if((nums[j]-nums[j-1])!=-1){
                        return -1;
                    }
                }
                for(int j=maxp+1;j<n;j++){
                    if((nums[j]-nums[j-1])!=-1){
                        return -1;
                    }
                }
        }else if(maxp<minp){
              for(int j=1;j<=maxp;j++){
                    if((nums[j]-nums[j-1])!=1){
                        return -1;
                    }
                }
                for(int j=minp+1;j<n;j++){
                    if((nums[j]-nums[j-1])!=1){
                        return -1;
                    }
                }
        }
        if(minp<maxp){
            return 1+min(minp+1,n-maxp);
        }
         int d=2+n-minp;
         int e=maxp+1;
         return min(d,e);
    }
};