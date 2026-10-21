class Solution {
private:
    bool needRemoval(deque<int>& minimals, int num) {
        return 0 < minimals.size() && num < minimals.back();
    }

    void updateMinimals(deque<int>& minimals, int num) {
        while(needRemoval(minimals, num)) {
            minimals.pop_back();
        }
    }

    void fillMinimals(vector<int>& nums, deque<int>& minimals) {
        for (int num: nums) {
            updateMinimals(minimals, num);
            minimals.push_back(num);
        }
    }

    void checkAndRemoveMinimal(deque<int>& minimals, int num) {
        if (num == minimals.front()) {
            minimals.pop_front();
        }
    }

    bool isStable(int maximal, int minimal, int k) {
        return (maximal - minimal) <= k;
    }

public:
    int firstStableIndex(vector<int>& nums, int k) {
        deque<int> minimals;
        fillMinimals(nums, minimals);
        int maximal = nums[0];
        for (int i = 0; i < nums.size(); i++) {
            maximal = max(maximal, nums[i]);
            if (isStable(maximal, minimals.front(), k)) {
                return i;
            }
            checkAndRemoveMinimal(minimals, nums[i]);
        }
        return -1;
    }
};
