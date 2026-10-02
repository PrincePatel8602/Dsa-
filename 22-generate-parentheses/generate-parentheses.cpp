class Solution {
public:
   vector<string>ans;
   void fun(int open,int close,string s,int n){

       if(open==n && close==n){
        ans.push_back(s);
        return ;
       }
      if(open<n){
            fun(open+1,close,s+'(',n);
      }
      if(open>close){
        fun(open,close+1,s+')',n);
      }

   }
    vector<string> generateParenthesis(int n) {
         fun(0,0,"",n);
         return ans;
    }
};