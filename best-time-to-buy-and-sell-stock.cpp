class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int maximalProfit = 0;
        int currentMinimal = 100000;
        for (int price : prices) {
            currentMinimal = min(currentMinimal, price);
            maximalProfit = max(maximalProfit, price - currentMinimal);
        }
        return maximalProfit;
    }
};
