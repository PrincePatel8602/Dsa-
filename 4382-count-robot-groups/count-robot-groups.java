class Solution {
    public int countGroups(int[] position, int[] speed, int distance) {
        int  count =1;
        int minSped = speed[speed.length-1];
        
        for(int i=speed.length-1;i>=1;i--){
            if(minSped >=speed[i-1] && position[i]-position[i-1] > distance){       
                minSped= speed[i-1];             
                count++;
            }
        }
        return count;
    }
}