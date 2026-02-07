class Solution {
public:
    int minimumOperations(vector<int>& nums) {
        int operations = 0;
        for (int num : nums) {
            operations += (num % 3) != 0 ? 1 : 0;
        }
        return operations;
    }
};
