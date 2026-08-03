class Solution {
public:
    int canCompleteCircuit(vector<int>& gas, vector<int>& cost) {
        int current = gas[0] - cost[0];
        int minimal = current;
        int index = 0;
        for (int i = 1; i < gas.size(); i++) {
            current += gas[i] - cost[i];
            if (current < minimal) {
                minimal = current;
                index = i;
            }
        }
        if (0 <= current) {
            return (index + 1) % gas.size();
        }
        return -1;
    }
};
