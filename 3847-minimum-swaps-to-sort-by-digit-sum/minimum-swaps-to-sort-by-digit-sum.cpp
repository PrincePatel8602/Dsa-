class Solution {
public:
    int minSwaps(vector<int>& nums) {
        int n = nums.size();
        unordered_map<int,int>mp;
        for (int i = 0; i < n; i++) {
            int x = nums[i], sum = 0;
            while (x > 0) {
                sum += x % 10;
                x /= 10;
            }
           mp[nums[i]]=sum;
        }
        vector<int>temp(n);
        for(int i=0;i<n;i++){
            temp[i]=nums[i];
                   }

    sort(nums.begin(), nums.end(), [&](int a, int b) {
    int x = a, y = b;
   
    if (mp[x]==mp[y]){
        return a < b;
    }
    return mp[x] < mp[y];
});
   unordered_map<int,int>pos;
   for(int i=0;i<n;i++){
      pos[nums[i]]=i;
   }
     int i=0;
     int ans=0;
     while(i<n){
        if(nums[i]==temp[i]){
            i++;
            continue;
        }else{
            int c=pos[temp[i]];
            int d=temp[c];
            temp[c]=temp[i];
            temp[i]=d;
            ans++;
        }
     }

       return ans;
    }
};