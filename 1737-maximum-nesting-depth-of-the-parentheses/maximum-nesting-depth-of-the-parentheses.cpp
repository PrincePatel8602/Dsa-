class Solution {
public:
    int maxDepth(string s) {
       int ans=0;
       int n=s.size();
       int p=0;
       for(int i=0;i<n;i++){
        if(s[i]=='('){
            p++;
            ans=max(ans,p);
        }else if(s[i]==')'){
            p--;
            ans=max(ans,p);
        }
       }
       return ans; 
    }
};