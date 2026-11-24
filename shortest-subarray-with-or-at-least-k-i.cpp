class Solution {
private:
    int getCandidate(const vector<int>& nums, int k, int i) {
        int orSum = 0;
        for (int j = i; j < nums.size(); j++) {
            orSum |= nums[j];
            if (k <= orSum) return j - i + 1;
        }
        return -1;
    }

    int testAndUpdate(int l, int candidate) {
        if (l == -1) return candidate;
        if (candidate == -1) return l;
        return min(l, candidate);
    }

public:
    int minimumSubarrayLength(const vector<int>& nums, int k) {
        int l = -1;
        for (int i = 0; i < nums.size(); i++) {
            int candidate = getCandidate(nums, k, i);
            l = testAndUpdate(l, candidate);
        }
        return l;
    }
};
