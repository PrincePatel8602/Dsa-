class Solution {
public:
    vector<int> resultArray(vector<int>& nums) {
        int n=nums.size();
        vector<int>a;
        vector<int>b;
        a.push_back(nums[0]);
        b.push_back(nums[1]);
        for(int i=2;i<n;i++){
        if(a.back()>b.back()){
            a.push_back(nums[i]);
        }else{
            b.push_back(nums[i]);
        }
        }
        vector<int>r;
        for(int i=0;i<a.size();i++){
            r.push_back(a[i]);
        }
          for(int i=0;i<b.size();i++){
            r.push_back(b[i]);
        }
        return r;
    }
};