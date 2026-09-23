class Solution {
    public int[] twoSum(int[] nums, int target) {
        int n=nums.length;
        HashMap<Integer,Integer>v=new HashMap<>();
        v.put(nums[0],0);
        for(int i=1;i<n;i++){
            int need=target-nums[i];
            if(v.containsKey(need)){
                return new int[]{v.get(need),i};
            }
            v.put(nums[i],i);
        }
        
        return new int[]{-1,-1};
    }
}