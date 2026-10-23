class Solution {
public:
    int sortPermutation(vector<int>& nums) {
        int n=nums.size();
        bool ok=true;
        for(int i=0;i<n;i++){
            if(nums[i]!=i){
                ok=false;
                break;
            }
        }
        if(ok){
            return 0;
        }
        int b=0;
        for(int i=0;i<32;i++){
            bool flag=true;
            for(int j=0;j<n;j++){
                if(nums[j]!=j){
                    if(!((1<<i)&nums[j])){
                        flag=false;
                    }
                }
            }
            if(flag){
                b=b|(1<<i);
            }
        }
        return b;
    }
};