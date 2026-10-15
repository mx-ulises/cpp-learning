class Solution {
private:
    int checkAndAdd(vector<int>& list, int num, int i, int largestPrev, int tailIndex) {
        if (largestPrev < num) {
            list.push_back(num);
            tailIndex = i;
        }
        return tailIndex;
    }

    int fillList(vector<int>& nums, vector<int>& list, int start, int end, int step) {
        int largestPrev = 0;
        int i = start;
        int tailIndex = -1;
        while(i != end) {
            tailIndex = checkAndAdd(list, nums[i], i, largestPrev, tailIndex);
            largestPrev = max(nums[i], largestPrev);
            i += step;
        }
        return tailIndex;
    }

    int fillListAndReverse(vector<int>& nums, vector<int>& list, int start, int end, int step) {
        int tailIndex = fillList(nums, list, start, end, step);
        reverse(list.begin(), list.end());
        return tailIndex;
    }

public:
    vector<int> findValidElements(vector<int>& nums) {
        vector<int> leftList;
        vector<int> rightList;
        int rightEnd = fillList(nums, leftList, 0, nums.size(), 1);
        fillListAndReverse(nums, rightList, nums.size() - 1, rightEnd, -1);
        leftList.insert(leftList.end(), rightList.begin(), rightList.end());
        return leftList;
    }
};
