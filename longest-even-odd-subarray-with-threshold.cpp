struct SubarrayStatus {
    int currentLen;
    int expectedParity;
};

class Solution {
private:
    int getParity(int num) {
        return num & 1;
    }

    bool isValidElement(int num, int expectedParity, int threshold) {
        return getParity(num) == expectedParity && num <= threshold;
    }

    SubarrayStatus updateSubarrayStatus(SubarrayStatus subarrayStatus, int num, int threshold) {
        if (isValidElement(num, subarrayStatus.expectedParity, threshold)) {
            subarrayStatus.currentLen++;
            subarrayStatus.expectedParity ^= 1;
        } else {
            subarrayStatus = {0, 0};
        }
        return subarrayStatus;
    }

    bool isZeroSubarrayStatus(SubarrayStatus subarrayStatus) {
        return subarrayStatus.currentLen == 0;
    }

public:
    int longestAlternatingSubarray(vector<int>& nums, int threshold) {
        int longestLen = 0;
        SubarrayStatus subarrayStatus = {0, 0};
        for (int num : nums) {
            subarrayStatus = updateSubarrayStatus(subarrayStatus, num, threshold);
            if (isZeroSubarrayStatus(subarrayStatus)) {
                subarrayStatus = updateSubarrayStatus(subarrayStatus, num, threshold);
            }
            longestLen = max(longestLen, subarrayStatus.currentLen);
        }
        return longestLen;
    }
};
