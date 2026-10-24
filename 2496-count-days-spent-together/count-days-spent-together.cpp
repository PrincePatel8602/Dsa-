class Solution {
public:
    int fun(vector<int>&pre,string a){
        int mo=stoi(a.substr(0,2));
        int da=stoi(a.substr(3,2));
        return pre[mo-1]+da;
    }
    int countDaysTogether(string arriveAlice, string leaveAlice, string arriveBob, string leaveBob) {
        vector<int>pre(12,0);
        pre[0]=0;
        pre[1]=31;
        pre[2]=59;
        pre[3]=90;
        pre[4]=120;
        pre[5]=151;
        pre[6]=181;
        pre[7]=212;
        pre[8]=243;
        pre[9]=273;
        pre[10]=304;
        pre[11]=334;
        int aa=fun(pre,arriveAlice);
        int la=fun(pre,leaveAlice);
        int ab=fun(pre,arriveBob);
        int lb=fun(pre,leaveBob);
         return max(0, min(la, lb) -
                          max(aa, ab) + 1);
        

    }
};