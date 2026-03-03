class Solution {
private:
    vector<int> buildIntersectionMap(vector<int>& nums1, vector<int>& nums2) {
        vector<int> intersectionMap(101);
        addElements(intersectionMap, nums1, 1);
        addElements(intersectionMap, nums2, 2);
        return intersectionMap;
    }

    void addElements(vector<int>& intersectionMap, vector<int>& nums, int bit) {
        for (int num : nums) {
            intersectionMap[num] |= bit;
        }
    }

    int getIntersectingElements(vector<int>& intersectionMap, vector<int>& nums, int mask) {
        int intersectinElements = 0;
        for (int num : nums) {
            if (intersectionMap[num] == mask) {
                intersectinElements++;
            }
        }
        return intersectinElements;
    }

public:
    vector<int> findIntersectionValues(vector<int>& nums1, vector<int>& nums2) {
        vector<int> intersectionMap = buildIntersectionMap(nums1, nums2);
        int intersectinElements1 = getIntersectingElements(intersectionMap, nums1, 3);
        int intersectinElements2 = getIntersectingElements(intersectionMap, nums2, 3);
        return {intersectinElements1, intersectinElements2};
    }
};
