class Solution {
public:
    vector<int> busiestServers(int k, vector<int>& arrival, vector<int>& load) {
        int n=arrival.size();
        set<int>free;
        for(int i=0;i<k;i++){
            free.insert(i);
        }
        priority_queue<pair<long long,int>,vector<pair<long long,int>>,greater<pair<long long,int>>>busy;

        vector<int>ans(k,0);
        vector<int>np;
        for(int i=0;i<n;i++){
            int t=arrival[i];
            while(!busy.empty() && busy.top().first<=t){
                free.insert(busy.top().second);
                busy.pop();

            }
            if(free.empty()){
                continue;
            }
            int pre=i%k;
            auto it=free.lower_bound(pre);
            if(it==free.end()){
               it=free.begin();
            }
            ans[*it]++;

            busy.push({t+load[i],*it});
            free.erase(it);

        }
        int c=*(max_element(ans.begin(),ans.end()));
        for(int i=0;i<k;i++){
            if(c==ans[i]){
               np.push_back(i);
            }
        }
        return np;
    }
};