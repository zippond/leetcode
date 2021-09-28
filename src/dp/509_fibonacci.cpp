class Solution {
public:
    int fib(int n) {
        if(n < 2) return n;
        int pre = 1, cur = 1, sum = 1;
        for(int i = 2; i< n;i++)
        {
            sum = cur + pre;
            pre = cur;
            cur = sum;
        }
        return sum;
    }
};