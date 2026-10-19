class Solution {
public:
    int findColoredRoot(vector<vector<int>>& edges, string colors) {
        int n=colors.size();
        vector<int>in(n);
        vector<int>out(n);
        unordered_map<char,char>mp;
        mp['R']='B';
        mp['B']='W';
        mp['W']='R';
        for(auto it:edges){
            int u=it[0];
            int v=it[1];
            char uc=colors[u];
            char vc=colors[v];
            if(uc==vc){
                return -1;
            }else if(mp[uc]==vc){
                in[v]++;
                out[u]++;
            }else{
                in[u]++;
                out[v]++;
            }
        }
        int root=-1;
        for(int i=0;i<n;i++){
           if(in[i]>1){
            return -1;
           }else if(out[i]>2){
            return -1;
           }else if(in[i]==0){
               root=i;
           }
        }
          return root;
    }
};