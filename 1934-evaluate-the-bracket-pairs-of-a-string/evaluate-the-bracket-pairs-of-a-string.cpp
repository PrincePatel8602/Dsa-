class Solution {
public:
    string evaluate(string s, vector<vector<string>>& knowledge) {
       int n= knowledge.size();
       unordered_map<string,string>mp;
       for(int i=0;i<n;i++){
             mp[knowledge[i][0]]=knowledge[i][1];
       }   
       bool check=false;
       int np=s.size();
       string ans="";
        string sp="";
       for(int i=0;i<np;i++){
          
        if(s[i]!='(' && s[i]!=')' && check==false){
             ans+=s[i];
        }else if(s[i]=='('){
            sp="";
            check=true;
        }else if(s[i]==')'){
           
            if(mp.find(sp)!=mp.end()){
              
                ans+=mp[sp];
            }else{
                ans+='?';
            }
            sp="";
            check=false;
        }else if(s[i]!='(' && s[i]!=')' && check==true){
            sp+=s[i];
        }
       }
       return ans;
    }
};