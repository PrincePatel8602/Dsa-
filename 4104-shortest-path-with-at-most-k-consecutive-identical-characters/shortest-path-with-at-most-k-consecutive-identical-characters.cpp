class Solution {
public:
    int shortestPath(int n, vector<vector<int>>& edges, string labels, int k) {
        int np=edges.size();
        vector<vector<pair<int,int>>>adj(n);
        for(int i=0;i<np;i++){
            adj[edges[i][0]].push_back({edges[i][1],edges[i][2]});
        }
        long long x=1e18;
        vector<vector<long long>>dist(n,vector<long long >(k+1,x));
        priority_queue<pair<long long,pair<int,int>>,vector<pair<long long,pair<int,int>>>,greater<pair<long long,pair<int,int>>>>pq;
        pq.push({0,{0,1}});
        dist[0][1]=0;
        while(!pq.empty()){
            auto node=pq.top();
            long long dis=node.first;
            int no=node.second.first;
            int nc=node.second.second;
            pq.pop();
            if(dis!=dist[no][nc]){
                continue;
            }
            for(auto it:adj[no]){
                int newCount;

                if(labels[it.first] == labels[no]) {
                    newCount = nc + 1;
                }
                else {
                    newCount = 1;
                }

                if(newCount > k) continue;

                if(dist[it.first][newCount] > dis + it.second) {
                    dist[it.first][newCount] = dis + it.second;

                    pq.push({dis + it.second, {it.first, newCount}});
                }
            }
        }
        long long ans=x;
        for(int i=0;i<=k;i++){
             ans=min(ans,dist[n-1][i]);
        }
        if(ans==x){
            return -1;
        }
        return ans;

    }
};