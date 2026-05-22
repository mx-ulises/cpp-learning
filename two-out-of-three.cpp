class Solution {
private:
    void updateNumMap(unordered_map<int, int>& numMap, vector<int>& nums, int flag) {
        for (int num: nums) {
            numMap[num] |= flag;
        }
    }

    bool isValidNumber(int i, unordered_set<int>& flags) {
        return find(flags.begin(), flags.end(), i) == flags.end();
    }

public:
    vector<int> twoOutOfThree(vector<int>& nums1, vector<int>& nums2, vector<int>& nums3) {
        unordered_map<int, int> numMap;
        unordered_set<int> flags({0, 1, 2, 4});
        updateNumMap(numMap, nums1, 1);
        updateNumMap(numMap, nums2, 2);
        updateNumMap(numMap, nums3, 4);
        vector<int> output;
        for (const auto& [num, mask] : numMap) {
            if (isValidNumber(mask, flags)) {
                output.push_back(num);
            }
        }
        return output;
    }
};
