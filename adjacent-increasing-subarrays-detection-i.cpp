class Solution {
private:
    int getStreakValue(int prev, int current, int prevStreak) {
        if (prev < current) return 1 + prevStreak;
        return 1;
    }

    bool checkStreakSize(int streak, int k) {
        return k <= streak;
    }

    bool checkConsecutiveStreakSize(vector<int>& increasingStreak, int i, int k) {
        return checkStreakSize(increasingStreak[i], k) && checkStreakSize(increasingStreak[i - k], k);
    }

public:
    bool hasIncreasingSubarrays(vector<int>& nums, int k) {
        vector<int> increasingStreak(nums.size());
        increasingStreak[0] = 1;
        for (int i = 1; i < nums.size(); i++) {
            increasingStreak[i] = getStreakValue(nums[i - 1], nums[i], increasingStreak[i - 1]);
        }
        for(int i = k; i < increasingStreak.size(); i++) {
            if (checkConsecutiveStreakSize(increasingStreak, i, k)) return true;
        }
        return false;
    }
};
