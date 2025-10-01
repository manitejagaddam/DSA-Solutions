class Solution {
public:
    int numWaterBottles(int numBottles, int numExchange) {
        // return numBottles + (numBottles/numExchange) + 1;
        
        int drank = numBottles;
        int empty = numBottles;
        
        while (empty >= numExchange) {
            int full = empty / numExchange;
            empty = empty % numExchange + full;
            drank += full;
        }
        
        return drank;
    }
};