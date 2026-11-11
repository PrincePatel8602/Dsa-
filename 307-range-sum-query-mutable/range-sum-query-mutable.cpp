class NumArray {
public:
    vector<int>seg;
    int n;
    void build(int i,int low,int high,vector<int>&nums){
        if(low==high){
            seg[i]=nums[low];
            return ;
        }
        int mid=low+(high-low)/2;
        build(2*i,low,mid,nums);
        build(2*i+1,mid+1,high,nums);
        seg[i]=seg[2*i+1]+seg[2*i];
    }
    void up(int ind,int low,int high,int i,int val){
          if(low==high){
            seg[i]=val;
            return ;
          }
          int mid=low+(high-low)/2;
          if(ind<=mid){
            up(ind,low,mid,2*i,val);
          }else{
            up(ind,mid+1,high,2*i+1,val);
          }
          seg[i]=seg[2*i]+seg[2*i+1];
    }
    int rangesum(int ind,int low,int high,int l,int r){
         if(high<l || r<low){
            return 0;
         }
         if(low>=l && high<=r){
            return seg[ind];
         }
         int mid=low+(high-low)/2;
         int left=rangesum(2*ind,low,mid,l,r);
         int right=rangesum(2*ind+1,mid+1,high,l,r);
         return left+right;
    }
    NumArray(vector<int>& nums) {
         n=nums.size();
        seg.assign(4*n,0);
        build(1,0,n-1,nums);
    }
    
    void update(int index, int val) {
       up(index,0,n-1,1,val); 
    }
    
    int sumRange(int left, int right) {
        return rangesum(1,0,n-1,left,right);
    }
};

/**
 * Your NumArray object will be instantiated and called as such:
 * NumArray* obj = new NumArray(nums);
 * obj->update(index,val);
 * int param_2 = obj->sumRange(left,right);
 */