class Solution {
public:
    int twoCitySchedCost(vector<vector<int>>& costs) {
        int n=costs.size();
        vector<pair<int,int>>mp;
        for(int i=0;i<n;i++){
            int c=costs[i][0]-costs[i][1];
            mp.push_back({c,i});
        }
        sort(mp.begin(),mp.end());
        int ans=0;
        for(int i=0;i<n/2;i++){
            ans+=costs[mp[i].second][0];
        }
        for(int i=n/2;i<n;i++){
             ans+=costs[mp[i].second][1];
        }
        return ans;
    }
};