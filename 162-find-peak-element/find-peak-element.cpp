class Solution {
public:
    int findPeakElement(vector<int>& nums) {
        int n=nums.size();
        int l=0;
        int h=n-1;
        while(l<=h){
            int mid=l+(h-l)/2;
            if(((mid-1>=0 && nums[mid]>nums[mid-1])&& (mid+1<n && nums[mid]>nums[mid+1])) || ((mid+1<n && nums[mid]>nums[mid+1]) && mid-1<0)
            ||   ((mid-1>=0 && nums[mid]>nums[mid-1]) && mid+1>=n) || (mid-1<0 && mid+1>=n)){
        return mid;
}  
   if(mid+1<n && nums[mid+1]>nums[mid]){
    l=mid+1;
   } else if(mid-1>=0 && nums[mid-1]>nums[mid]){
    h=mid-1;
   }
  }
  return -1;
    }
};