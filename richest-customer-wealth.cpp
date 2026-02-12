class Solution {
private:
    int sum(vector<int>& customer) {
        int customerWealth = 0;
        for (int accountBalance : customer) {
            customerWealth += accountBalance;
        }
        return customerWealth;
    }

public:
    int maximumWealth(vector<vector<int>>& accounts) {
        int maximumCustomerWealth = 0;
        for (vector<int> customer : accounts) {
            maximumCustomerWealth = max(maximumCustomerWealth, sum(customer));
        }
        return maximumCustomerWealth;
    }
};
