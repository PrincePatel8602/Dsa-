class NumArray {
public:

vector<int>seg;
int n;
    void build(int i,int l,int r,vector<int>&nums){
        if(l==r){
            seg[i]=nums[r];
            return ;
        }
        int mid=l+(r-l)/2;
        build(2*i+1,l,mid,nums);
        build(2*i+2,mid+1,r,nums);
        seg[i]=seg[2*i+1]+seg[2*i+2];
    }
    void update(int idx,int val,int i,int l,int r){
        if(l==r){
            seg[i]=val;
            return;
        }
        int mid=l+(r-l)/2;
        if(idx<=mid){
            update(idx,val,2*i+1,l,mid);
        }else{
             update(idx,val,2*i+2,mid+1,r);
        }
        seg[i]=seg[2*i+1]+seg[2*i+2];
    }
    int sumquery(int start,int end,int i,int l,int r){
        if(r<start || l>end){
            return 0;
        }
        if(start<=l && end>=r){
            return seg[i];
        }
        int mid=l+(r-l)/2;
        return sumquery(start,end,2*i+1,l,mid)+sumquery(start,end,2*i+2,mid+1,r);

    }
    NumArray(vector<int>& nums) {
      n=nums.size();
       seg.assign(4*n,0);
       build(0,0,n-1,nums); 
    }
    
    void update(int index, int val) {
        return update(index,val,0,0,n-1);
    }
    
    int sumRange(int left, int right) {
     return sumquery(left,right,0,0,n-1);
    }
};

