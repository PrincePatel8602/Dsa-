class Solution {
public:
    int ans = 0;
    unordered_map<int,int> mp;

    void fun(int i, int n, int k, vector<int>& nums) {

        if(i == n) {
            ans++;
            return;
        }

        bool flag = true;

        for(auto it : mp) {
            if(abs(nums[i] - it.first) == k) {
                flag = false;
                break;
            }
        }

        
        if(flag) {
            mp[nums[i]]++;

            fun(i + 1, n, k, nums);

            mp[nums[i]]--;

            if(mp[nums[i]] == 0)
                mp.erase(nums[i]);
        }
        fun(i + 1, n, k, nums);
    }

    int beautifulSubsets(vector<int>& nums, int k) {
        ans = 0;
        mp.clear();

        fun(0, nums.size(), k, nums);

        return ans - 1;
    }
};