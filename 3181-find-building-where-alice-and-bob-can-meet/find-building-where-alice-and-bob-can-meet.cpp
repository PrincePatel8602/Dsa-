class Solution {
public:
    vector<int>seg;
    // for buiding segment tree//
    void build(int i,int l,int r,vector<int>&heights){
        if(l==r){
            seg[i]=l;
            return;
        }
        int mid=l+(r-l)/2;
        build(2*i+1,l,mid,heights);
        build(2*i+2,mid+1,r,heights);
        int left=seg[2*i+1];
        int right=seg[2*i+2];
        seg[i]=(heights[left]>=heights[right])?left:right;
    }
    // for finding maximum from certain range//
    int query(int s,int e,int i,int l,int r,vector<int>&heights){
        if(r<s || l>e){
            return -1;
        }
        if(s<=l && r<=e){
            return seg[i];
        }
        int mid=l+(r-l)/2;
        int left=query(s,e,2*i+1,l,mid,heights);
        int right=query(s,e,2*i+2,mid+1,r,heights);
        if(left==-1){
            return right;
        }
        if(right==-1){
            return left;
        }
        return (heights[left]>heights[right])?left:right;

        
    }
    int RMIQ(vector<int>&heights,int n,int a,int b){
        return query(a,b,0,0,n-1,heights);
    }
    vector<int> leftmostBuildingQueries(vector<int>& heights, vector<vector<int>>& queries) {
        int n=heights.size();
        seg.resize(4*n);
        build(0,0,n-1,heights);
        vector<int>ans;
        for(auto q:queries){
            int mini=min(q[0],q[1]);
            int maxi=max(q[0],q[1]);
            if(mini==maxi){
                ans.push_back(maxi);
                continue;
            }
            if(heights[maxi]>heights[mini]){
                ans.push_back(maxi);
                continue;
            }
            int l=maxi+1;
            int r=n-1;
            int resi=-1;
            int target=max(heights[mini],heights[maxi]);
            // this bs is used for finding max from l to mid if not possible then go mid+1 else push -1//
            while(l<=r){
                int mid=l+(r-l)/2;
                int idx=RMIQ(heights,n,l,mid);
                if(idx!=-1 && heights[idx]>target){
                    resi=idx;
                    r=mid-1;
                }else{
                    l=mid+1;
                }
            }
              ans.push_back(resi);
        }
        return ans;
    }
};