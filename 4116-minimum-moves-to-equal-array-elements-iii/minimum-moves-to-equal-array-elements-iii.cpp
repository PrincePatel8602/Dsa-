class Solution {
public:
    int minMoves(vector<int>& nums) {
        int n=nums.size();
        int cp=INT_MIN;
        for(int i=0;i<n;i++){
            cp=max(cp,nums[i]);
        }
        int sum=0;
        for(int i=0;i<n;i++){
              sum+=abs(nums[i]-cp);
        }
        return sum;
    }
};