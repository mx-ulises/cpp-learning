class Solution {
private:
    void addNums(vector<int>& intersectionMap, const vector<int>& nums, int bit) {
        for (auto num : nums) {
            intersectionMap[num] |= bit;
        }
    }

    void getInstersectingValues(vector<int>& output, const vector<int>& intersectionMap, int mask) {
        for (int i = 0; i < intersectionMap.size(); i++) {
            if (intersectionMap[i] == mask) {
                output.push_back(i);
            }
        }
    }

public:
    vector<int> intersection(vector<int>& nums1, vector<int>& nums2) {
        vector<int> intersectionMap(1001);
        addNums(intersectionMap, nums1, 1);
        addNums(intersectionMap, nums2, 2);
        vector<int> output;
        getInstersectingValues(output, intersectionMap, 3);
        return output;
    }
};
