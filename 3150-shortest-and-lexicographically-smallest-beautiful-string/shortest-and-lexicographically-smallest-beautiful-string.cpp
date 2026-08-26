class Solution {
public:
    string shortestBeautifulSubstring(string s, int k) {
        string sp=s;
        
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
                if(r-l<sp.size()){
                    sp=s.substr(l,r-l);
                }else if(r-l==sp.size()){
                    sp=min(sp,s.substr(l,r-l));
                }
                while(one>=k){
                    if(s[l]=='1'){
                       
                        one--;
                    }
                    l++;
                    if(one==k && r-l<sp.size()){
                    sp=s.substr(l,r-l);
                }else if(one==k && r-l==sp.size()){
                    sp=min(sp,s.substr(l,r-l));
                }
                    
                }
            }

        }
        int onep=0;
        for(int i=0;i<s.size();i++){
            if(s[i]=='1'){
                onep++;
            }
        }
        if(sp==s && onep==k){
            return sp;
        }else if(sp!=s){
            return sp;
        }
        return "";
    }
};