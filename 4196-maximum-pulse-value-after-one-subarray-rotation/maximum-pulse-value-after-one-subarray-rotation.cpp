class Solution {
public:
    long long maxValue(vector<int>& nums) {
        int n = nums.size();

        vector<int> num;

        for(int i = 0; i < n; i++) {
            if(i % 2 == 0)
                num.push_back(nums[i]);
            else
                num.push_back(-nums[i]);
        }

        long long sum = 0;

        for(int i = 0; i < n; i++) {
            sum += num[i];
        }

        long long ans = INT_MAX;
        long long sump = 0;

        for(int i = 0; i + 1 < n; i += 2) {
            int x = num[i] + num[i + 1];

            sump = min((long long)x, sump + x);
            ans = min(ans, sump);
        }

        sump = 0;

        for(int i = 1; i + 1 < n; i += 2) {
            int x = num[i] + num[i + 1];

            sump = min((long long)x, sump + x);
            ans = min(ans, sump);
        }

        if(ans < 0) {
            sum += 2LL * abs(ans);
        }

        return sum;
    }
};