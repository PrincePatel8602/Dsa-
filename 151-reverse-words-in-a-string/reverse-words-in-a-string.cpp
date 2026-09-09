class Solution {
public:
    string reverseWords(string s) {
        int n= s.size();
       
        string sp="";
        
        reverse(s.begin(),s.end());
        int j=0;
       for(int i=0;i<n;i++){
        if(s[i]==' '){
           j++;
        }else{
            break;
        }
       }
      
        int l=j;
        int r=j;
        for(int i=j;i<s.size();i++){
           
          
        if(s[i]==' ' && (i-1>=0 && s[i-1]!=' ')){
            string cp=" ";
            
            cp+=(s.substr(l,r-l));
            reverse(cp.begin(),cp.end());
            sp+=cp;
            r++;
            l=r;
        }
        else if(s[i]==' '){
            r++;
            l++;
            
        }else{
            r++;
        }
        }
        if(s[s.size()-1]!=' '){
          string cp=" ";
         
        cp+=s.substr(l,r-l+1);
         reverse(cp.begin(),cp.end());
         sp+=cp;
        
        }
         return sp.substr(0,sp.size()-1);
    }
};