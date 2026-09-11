class Solution {
public:
    set<string>sp;
    void fun(vector<int>& digits,string s,vector<int>&used){
        
        if (s.size() == 3){
            if((s.back() - '0') % 2 == 0){
           sp.insert(s);
            
        }
            return;
        }
    
        for(int j=0;j<digits.size();j++){
            if(used[j]==1){
                continue;
            }
            if(digits[j]==0 && s.size()==0){
                continue;
            }

            used[j]=1;
            fun(digits,s+char(digits[j]+'0'),used);
            used[j]=0;
        }
    }
    int totalNumbers(vector<int>& digits) {
        vector<int>used(digits.size(),0);
        fun(digits,"",used);
        return sp.size();
    }
};