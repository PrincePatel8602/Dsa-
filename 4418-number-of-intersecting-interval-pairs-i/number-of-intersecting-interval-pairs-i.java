class Solution {
    public int countIntersectingIntervals(int[][] intervals) {
        int n=intervals.length;
        int ans=0;
        Arrays.sort(intervals, (a, b) -> a[0] - b[0]);
        for(int i=0;i<n;i++){
            for(int j=i+1;j<n;j++){
                if(intervals[j][0]<=intervals[i][1] ){
                    ans++;
                }
            }
        }

        return ans;
    }
}