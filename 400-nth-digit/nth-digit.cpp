class Solution {
public:
    int findNthDigit(int n) {
        long base=1, len=1;
        while(n>9*base*len){
            n-=9*base*len;
            base*=10;
            len++;
        }
        long num = base + (n-1)/len;
        return to_string(num)[(n-1)%len] - '0';
    }
};