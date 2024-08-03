class Solution {
public:
    bool isPerfectSquare(int num) {
        int i;
        for(i =1; i<=num/i; i++){continue;}
        return (i-1)*(i-1) == num;
    }
// the following solution uses the properties of the odd numbers.. elegent;
    bool isPerfectSquareUsingOdds(int num) {
       int i=1;
       while(num>0){
        num-=i;
        i+=2;
        if(!num) return true;

       }  
       return false;     
    }
};
