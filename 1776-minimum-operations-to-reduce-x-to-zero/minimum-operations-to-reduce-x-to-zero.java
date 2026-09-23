class Solution {
    public int minOperations(int[] nums, int x) {
       int n=nums.length;
       // vector<int>pre;
       ArrayList<Integer>pre=new ArrayList<>();
        HashMap<Integer,Integer>suff=new HashMap<>();
        int p=0, s=0;
        int ans =Integer.MAX_VALUE;
        for(int i=0;i<n;i++){
            p+=nums[i];
            pre.add(p);
            s+=nums[n-1-i];
            suff.put(s,i);
            if(p==x || s==x){
                ans =Math.min(ans,i+1);
            }
        }

        for(int i=0; i<n; i++){
            int req = x-pre.get(i);
            if(suff.containsKey(req)){
                int op = i+1+suff.get(req)+1;
                ans = Math.min(ans,op);
            }
        }

        if(ans ==Integer.MAX_VALUE){
            return -1;
        }
        if(ans>n){
            return -1;
        }
        return ans;  
    }
}