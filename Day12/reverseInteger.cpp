class Solution {
public:
    int reverse(int x) {
        int original = x; 
        long long reversed = 0;
        bool sign = false;
        if(x == -2147483648) return 0;
        if(x<0) {
            x = abs(x);
            sign = true;}
        while(x){
            int digit = x % 10; 
            reversed = reversed *10 + digit; 
            x/=10;
        }
        
        if(reversed >= 2147483648) return 0;
        
        if(sign){
            reversed = reversed * (-1);
        }
        return reversed; 
        
    }
};
