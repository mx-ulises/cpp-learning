class Solution {
private:
    int getDigitRange(int num) {
        int largestDigit = num % 10;
        int smallestDigit = largestDigit;
        while (0 < num) {
            int digit = num % 10;
            largestDigit = max(largestDigit, digit);
            smallestDigit = min(smallestDigit, digit);
            num /= 10;
        }
        return largestDigit - smallestDigit;
    }

    void fillDigitRangeSums(vector<int>& nums, vector<int>& digitRangeSums) {
        for (int num : nums) {
            int digitRange = getDigitRange(num);
            digitRangeSums[digitRange] += num;
        }
    }

    int getMaxDigitRangeSum(vector<int>& digitRangeSums) {
        int maxDigitRangeSum = 0;
        for (int digitRangeSum : digitRangeSums) {
            if (digitRangeSum != 0) {
                maxDigitRangeSum = digitRangeSum;
            }
        }
        return maxDigitRangeSum;
    }

public:
    int maxDigitRange(vector<int>& nums) {
        vector<int> digitRangeSums(10);
        fillDigitRangeSums(nums, digitRangeSums);
        return getMaxDigitRangeSum(digitRangeSums);
    }
};
