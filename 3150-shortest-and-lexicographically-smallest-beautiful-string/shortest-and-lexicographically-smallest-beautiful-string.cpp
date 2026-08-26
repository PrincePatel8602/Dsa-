class Solution {
public:
    string shortestBeautifulSubstring(string s, int k) {
        string sp="";
        
        int  one=0;
        int zero=0;
        int l=0;
        int r=0;
        while(r<s.size()){
            if(s[r]=='1'){
                one++;

            }
            r++;
            if(one==k){
                while(l<r && s[l]=='0'){
                    l++;
                }
                string curr=s.substr(l,r-l);
                if(sp=="" || curr.size()<sp.size()){
                    sp=curr;
                }else if(curr.size()==sp.size()){
                    sp=min(sp,curr);
                }
                one--;
                l++;
            }
        }
        return sp;
      
    }
};