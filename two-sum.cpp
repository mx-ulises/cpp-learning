class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        unordered_map<int, int> visited;
        int candidate = 0;
        for (int i = 0; i < nums.size(); i++) {
            candidate = target - nums[i];
            if (visited.find(candidate) != visited.end()) {
                return vector<int>({visited[candidate], i});
            }
            visited.insert({nums[i], i});
        }
        return vector<int>();
    }
};
