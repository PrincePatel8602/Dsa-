class Solution {
public:
    int maxValidSplits(vector<int>& nums) {
        int n = nums.size();

       
        vector<int> mp(n);
        mp[0] = nums[0];

        for (int i = 1; i < n; i++) {
            mp[i] = gcd(nums[i], mp[i - 1]);
        }

       
        vector<int> mpp(n);
        mpp[n - 1] = nums[n - 1];

        for (int i = n - 2; i >= 0; i--) {
            mpp[i] = gcd(nums[i], mpp[i + 1]);
        }

        int ans = 0;

       
        for (int i = 0; i < n - 1; i++) {
            if (mp[i] == mpp[i + 1]) {
                ans++;
            }
        }

      
        for (int del = 0; del < n; del++) {

           
            vector<int> a;

            for (int i = 0; i < n; i++) {
                if (i != del) {
                    a.push_back(nums[i]);
                }
            }

            int sz = a.size();

            vector<int> mc(sz);

            mc[0] = a[0];

            for (int i = 1; i < sz; i++) {
                mc[i] = gcd(a[i], mc[i - 1]);
            }

            vector<int> mpc(sz);

            mpc[sz - 1] = a[sz - 1];

            for (int i = sz - 2; i >= 0; i--) {
                mpc[i] = gcd(a[i], mpc[i + 1]);
            }

            int count = 0;

            for (int i = 0; i < sz - 1; i++) {

                if (mc[i] == mpc[i + 1]) {
                    count++;
                }
            }

            ans = max(ans, count);
        }

        return ans;
    }
};