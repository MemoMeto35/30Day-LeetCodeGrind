// divide the dividend and divisor without using *, /, or %;
class Solution {
public:
    int divide(int dividend, int divisor) {
        if(dividend == divisor)
            return 1;
        if(dividend == INT_MIN && divisor == -1) return INT_MAX;
        bool isPositive = (dividend<0 == divisor<0);    // if both are of same sign, answer is positive
        unsigned int a = abs(dividend); // in range 0 to (1<<32)
        unsigned int b = abs(divisor);
        unsigned int ans = 0;
        while(a >= b){  // while dividend is greater than or equal to divisor
            int q = 0;
            while(a > (b<<(q+1)))
                q++;
            ans += (1<<q);  // add the power of 2 found to the answer
            a = a - (b<<q);  // reduce the dividend by divisor * power of 2 found
        }
        return isPositive ? ans : -ans;
    }
};
