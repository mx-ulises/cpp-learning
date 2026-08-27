class Solution {
public:
    bool containsNearbyDuplicate(vector<int>& nums, int k) {
        unordered_map<int, bool> visited;
        for(int i = 0; i < nums.size(); i++) {
            if (k < i) {
                int toBeRemoved = nums[i - k - 1];
                visited[toBeRemoved] = false;
            }
            int num = nums[i];
            if (visited.count(num) == 0) {
                visited[num] = false;
            }
            if (visited[num]) {
                return true;
            }
            visited[num] = true;
        }
        return false;
    }
};
