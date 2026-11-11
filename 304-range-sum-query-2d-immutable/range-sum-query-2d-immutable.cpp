class NumMatrix {
public:
     vector<vector<int>>seg;
     int m;
     int n;
     void build(int r,int i,int low,int high,vector<vector<int>>& matrix){
        if(low==high){
            seg[r][i]=matrix[r][low];
            return;
        }
        int mid=low+(high-low)/2;
        build( r,2*i,low,mid,matrix);
        build(r,2*i+1,mid+1,high,matrix);
        seg[r][i]=seg[r][2*i+1]+seg[r][2*i];
     }
     int range(int i,int r,int low,int high,int l,int rp){
        if(high<l || rp<low){
            return 0;
        }
        if(l<=low && high<=rp){
            return seg[r][i];
        }
        int mid=low+(high-low)/2;
        int left=range(2*i,r,low,mid,l,rp);
        int right=range(2*i+1,r,mid+1,high,l,rp);
        return left+right;
     }
    NumMatrix(vector<vector<int>>& matrix) {
        m=matrix.size();
        n=matrix[0].size();
        seg.assign(m,vector<int>(4*n,0));
        for(int i=0;i<m;i++){
             build(i,1,0,n-1,matrix);
        }
    }
    
    int sumRegion(int row1, int col1, int row2, int col2) {
        int sum=0;
        for(int j=row1;j<=row2;j++){
            sum+=range(1,j,0,n-1,col1,col2);
        }
        return sum;
    }
};

/**
 * Your NumMatrix object will be instantiated and called as such:
 * NumMatrix* obj = new NumMatrix(matrix);
 * int param_1 = obj->sumRegion(row1,col1,row2,col2);
 */