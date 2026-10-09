class Solution {
public:
    int minInsertions(string s) {
        int n=s.size();
        int open=0;
        int close=0;
        int ans=0;
        for(int i=0;i<n;i++){
           if(s[i]=='(' && close==1){
            if(open>=1){
              ans++;
              close--;
              open--;
            }else{
                cout<<"1"<<endl;
                close--;
                ans+=2;
               
            }
            open++;
           }else if(s[i]=='(' ){
                open++;
            }else{
            close++;
            if(close==2){
                if(open>=1){
                    open--;
                    close-=2;
                }else{
                    cout<<close<<endl;
                    ans++;
                    close-=2;
                }
            }
           }
        }
        cout<<ans<<endl;
        if(close==1){
            if(open>=1){
              ans++;
              close--;
              open--;
            }else{
                cout<<"1"<<endl;
                ans+=2;
               
            }
        }

        
        ans+=(2*open);

        return ans;
    }
};