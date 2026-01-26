class Solution {
public:
    vector<int> rearrangeArray(vector<int>& nums) {
        int positiveIndex = 0, negativeIndex = 0;
        vector<int> output = vector<int>(nums.size());
        for (int index = 0; index < output.size(); index++) {
            if (isEven(index)) {
                output[index] = findElementAndIncreaseIndex(nums, positiveIndex, 1);
            } else {
                output[index] = findElementAndIncreaseIndex(nums, negativeIndex, -1);
            }
        }
        return output;
    }

    bool isEven(int num) {
        return (num & 1) == 0;
    }

    int findElementAndIncreaseIndex(const vector<int>& nums, int & index, int sign) {
        while(getSign(nums[index]) != sign) {
            index++;
        }
        return nums[index++];
    }

    int getSign(int num) {
        return 0 < num ? 1 : -1;
    }
};
