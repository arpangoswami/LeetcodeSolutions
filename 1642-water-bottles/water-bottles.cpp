class Solution {
public:
    int numWaterBottles(int numBottles, int numExchange) {
        int ans = numBottles,emptyBottles = numBottles;
        while(emptyBottles >= numExchange){
            int add = emptyBottles/numExchange;
            emptyBottles = emptyBottles%numExchange + add;
            ans += add;
        }
        return ans;
    }
};