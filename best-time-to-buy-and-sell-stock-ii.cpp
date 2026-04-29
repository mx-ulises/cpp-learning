class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int profit = 0;
        int maximal = prices[0], minimal = prices[0];
        for(int price : prices) {
            if (price < maximal) {
                profit += maximal - minimal;
                minimal = price;
            }
            maximal = price;
        }
        profit += maximal - minimal;
        return profit;
    }
};
