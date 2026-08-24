class Solution {
public:
 int fun(vector<vector<int>>& matrix,int target){
    int count=0;
    int n=matrix.size();
    int m=matrix[0].size();
        for(int i=0;i<n;i++){
            int l=0;
            int h=m-1;
            int ans=0;
            while(l<=h){
                int mid=l+(h-l)/2;
                if(matrix[i][mid]>target){
                    h=mid-1;
                }else{
                    ans=mid+1;
                    l=mid+1;
                }
            }
            count+=ans;
        }
        return count;
 }
    int kthSmallest(vector<vector<int>>& matrix, int k) {
        int n=matrix.size();
        int m=matrix[0].size();
        int l=matrix[0][0];
        int h=matrix[n-1][m-1];
        int ansp=0;
        while(l<=h){
            int mid=l+(h-l)/2;
            int ans=fun(matrix,mid);
            
            if(ans<k){
                l=mid+1;
            }else{
                ansp=mid;
                h=mid-1;
            }
        }
        return ansp;
    }
};