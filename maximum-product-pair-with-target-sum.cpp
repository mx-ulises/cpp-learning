class Solution {
public:
    vector<int> maxProductPair(vector<int>& nums, int target) {
        vector<int> output({-1, -1});
        int maximal = -100000;
        unordered_map<int,int> visited;
        for (int i = 0; i < nums.size(); i++) {
            int a = nums[i];
            int b = target - a;
            if (a != b && visited.count(b) != 0 && maximal < (a * b)) {
                maximal = a * b;
                output[1] = visited[b];
                output[0] = i;
            }
            visited[a] = i;
        }
        return output;
    }
};
