class Solution {
public:
    int maxNumberOfFamilies(int n, vector<vector<int>>& reservedSeats) {
       int np=reservedSeats.size();
       unordered_map<int,vector<int>>mp;
       for(int i=0;i<np;i++){
        mp[reservedSeats[i][0]].push_back(reservedSeats[i][1]);
       }
       long long ansp=2*n;
       for(auto it:mp){
          vector<int>ans(8,0);
          for(int i=0;i<it.second.size();i++){
            if(it.second[i] >= 2 && it.second[i] - 2 < ans.size()) {
    ans[it.second[i] - 2] = 1;
}
          }
          int count=0;
          bool flag=false;
          for(int i=0;i<4;i++){
            if(ans[i]==1){
                flag=true;
            }
          }
          if(flag==false){
            for(int i=0;i<4;i++){
                ans[i]=1;
            }
            count++;
          }
         flag=false;
         for(int i=2;i<6;i++){
            if(ans[i]==1){
                flag=true;
            }
          }
          if(flag==false){
            for(int i=2;i<6;i++){
                ans[i]=1;
            }
            count++;
          }
         flag=false;
         for(int i=4;i<8;i++){
            if(ans[i]==1){
                flag=true;
            }
          }
          if(flag==false){
           
            count++;
          }
        ansp-=2;
        ansp+=count;
       }
       return ansp;
    }
};