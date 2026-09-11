class Solution {
public:
    int totalNumbers(vector<int>& digits) {
        int n=digits.size();
       unordered_set<string>mp;
        for(int i=0;i<n;i++){
            if(digits[i]==0){
                continue;
            }
            string s="";
            s+=char(digits[i]);
           for(int j=0;j<n;j++){
            if(j==i){
                continue;
            }
            string sp="";
            sp+=s;
            sp+=char(digits[j]);
            for(int k=0;k<n;k++){
               if(k==i || k==j  || digits[k]%2!=0){
                continue;
               }
               string sc="";
               sc+=sp;
               sc+=char(digits[k]);
               mp.insert(sc);
               
            }
           }
        }
        return mp.size();
    }
};