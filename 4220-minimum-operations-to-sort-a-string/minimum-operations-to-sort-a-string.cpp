class Solution {
public:
    int minOperations(string s) {
       int n=s.size();
        string sp=s;
        sort(sp.begin(),sp.end());
        if(sp==s){
            return 0;
        }
        if(sp[0]==s[0] || sp[n-1]==s[n-1]){
            return 1;
        }else if((sp[0]==s[n-1] && sp[n-1]==s[0])&& n>2 && sp[n-1]!=sp[n-2] && sp[0]!=sp[1]){
           return 3;
        }else if((sp[0]!=s[0] && sp[n-1]!=s[n-1])&& n>2){
            return 2;
        }
        return -1;
    }
};