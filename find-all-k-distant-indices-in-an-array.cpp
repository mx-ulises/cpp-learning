class Solution {
private:
    void addRange(vector<int>& output, int start, int end) {
        for(int i = start; i <= end; i++) {
            output.push_back(i);
        }
    }

public:
    vector<int> findKDistantIndices(vector<int>& nums, int key, int k) {
        vector<int> output;
        int minStart = 0;
        int maxEnd = nums.size() - 1;
        for(int i = 0; i < nums.size(); i++) {
            if (nums[i] == key) {
                int end = min(i + k, maxEnd);
                addRange(output, max(minStart, i - k), end);
                minStart = end + 1;
            }
        }
        return output;
    }
};
