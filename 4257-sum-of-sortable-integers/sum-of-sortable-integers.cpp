class Solution {
public:
    bool check(vector<int>&text, vector<int>&pat) {
    int n = text.size(), m = pat.size();
    
    vector<int> lps(m, 0);

    for (int i = 1, len = 0; i < m;) {
        if (pat[i] == pat[len]) {
            lps[i++] = ++len;
        } 
        else if (len > 0) {
            len = lps[len - 1];
        } 
        else {
            lps[i++] = 0;
        }
    }

    int i = 0, j = 0;

    while (i < n) {
        if (text[i] == pat[j]) {
            i++;
            j++;
        }

        if (j == m) return true;

        if (i < n && text[i] != pat[j]) {
            if (j > 0) j = lps[j - 1];
            else i++;
        }
    }

    return false;
}
    int sortableIntegers(vector<int>& nums) {
        int n=nums.size();
        vector<int>temp(nums.begin(),nums.end());
        sort(temp.begin(),temp.end());
        int sum=0;
        for(int k=1;k<=n;k++){
            bool ok=true;
            if(n%k!=0){
                continue;
            }else{
                
                for(int i=0;i<n;i+=k){
                    vector<int>vec1(nums.begin()+i,nums.begin()+i+k);
                    vector<int>vec2(temp.begin()+i,temp.begin()+i+k);
                    vec1.insert(vec1.end(), nums.begin() + i, nums.begin() + i + k);
                    if(!check(vec1,vec2)){
                        ok=false;
                        break;
                    }
                }
                if(ok){
                    sum+=k;
                }
            }
        }
        return sum;
    }
};