class Solution {
public:
    int minSelection(vector<vector<int>>& availableIntervals, vector<vector<int>>& targetIntervals) {
        int n = availableIntervals.size();
        int m = targetIntervals.size();

        sort(availableIntervals.begin(), availableIntervals.end());
        sort(targetIntervals.begin(), targetIntervals.end());

        if (m == 0) return 0;

        vector<vector<int>> tar;
        tar.push_back(targetIntervals[0]);

        for (int i = 1; i < m; i++) {
            if (targetIntervals[i][0] <= tar.back()[1]) {
                tar.back()[1] = max(tar.back()[1], targetIntervals[i][1]);
            } else {
                tar.push_back(targetIntervals[i]);
            }
        }

        int i = 0;
        int ans = 0;
        int nextmax = -1;

        for (auto &it : tar) {
            int s = it[0];
            int e = it[1];

            while (e > nextmax) {
                int curr = max(nextmax, s);
                int oldmax = nextmax;

                while (i < n && availableIntervals[i][0] <= curr) {
                    nextmax = max(nextmax, availableIntervals[i][1]);
                    i++;
                }

                if (nextmax == oldmax) {
                    return -1;
                }

                ans++;
            }
        }

        return ans;
    }
};