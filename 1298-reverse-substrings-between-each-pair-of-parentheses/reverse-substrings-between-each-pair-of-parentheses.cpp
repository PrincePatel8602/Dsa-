class Solution {
public:
    string reverseParentheses(string s) {
        int n=s.size();
        stack<char>st;
        for(int i=0;i<n;i++){
            if(s[i]==')'){
                string sp="";
                while(!st.empty() && st.top()!='('){
                    sp+=st.top();
                    st.pop();
                }
                st.pop();
               for(int i=0;i<sp.size();i++){
                st.push(sp[i]);
               }
            }else{
                st.push(s[i]);
            }
        }
        string ans="";
        while(!st.empty()){
            ans+=st.top();
            st.pop();
        }
       string an="";
       for(int i=ans.size()-1;i>=0;i--){
        an+=ans[i];
       }
       return an;
    }
};