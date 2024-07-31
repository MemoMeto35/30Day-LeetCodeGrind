class Solution {
public:
    int numWaterBottles(int numBottles, int numExchange) {
        int res = numBottles; 
        int currentAmount = numBottles; 
        while(currentAmount/numExchange){
            res += currentAmount/numExchange; 
            currentAmount = currentAmount/numExchange + (currentAmount%numExchange);
        }
        return res; 
    }
};
