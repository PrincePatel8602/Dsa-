class Solution {
public:
    vector<string> largestString(vector<int>& nums) {
        int n=nums.size();
        vector<string>ans;
        for(int i=0;i<n;i++){
            string ap="";
            int j=25;
            while(j>=0){
                if(nums[i]>=pow(2,j)){
                   nums[i]-=pow(2,j);
                   if(j!=25){
                   ap+=char('a'+j);
                   j--;
                   }else if(j==25){
                    ap+=char('a'+j);
                   }
                   
                }else{
                    j--;
                }
            }
            ans.push_back(ap);
        }
             return ans;
    }
};