class Solution {
public:
    bool sumGame(string num) {
        int n=num.size();
        int l=0;
        int lsum=0;
        int r=0;
        int rsum=0;
        for(int i=0;i<n/2;i++){
            if(num[i]=='?'){
                l++;
            }else {
                lsum+=int(num[i]-'0');
            }
        }
        for(int i=n/2;i<n;i++){
            if(num[i]=='?'){
                r++;
            }else {
                rsum+=int(num[i]-'0');
            }
        }
        return (lsum-rsum)!=(r-l)*4.5;
    }
};