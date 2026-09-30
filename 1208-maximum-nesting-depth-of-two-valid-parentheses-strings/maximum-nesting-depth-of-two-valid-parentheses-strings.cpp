class Solution {
public:
    vector<int> maxDepthAfterSplit(string seq) {
        int n=seq.size();
        vector<int>ans;
       
        int one=0;
        for(int i=0;i<n;i++){
            if(seq[i]=='('){
                one++;
                ans.push_back(one%2);
            }else{
                
                 ans.push_back(one%2);
                 one--;
            }
        }
        return ans;
    }
};