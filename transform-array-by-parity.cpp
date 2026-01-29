class Solution {
public:
    vector<int> transformArray(vector<int>& nums) {
        transformToBinaryArray(nums);
        sortBinaryArray(nums);
        return nums;
    }

    void transformToBinaryArray(vector<int>& nums) {
        for (int i = 0; i < nums.size(); i++) {
            nums[i] = nums[i] & 1;
        }
    }

    void sortBinaryArray(vector<int>& nums) {
        int left = findNextOne(nums, 0);
        int right = findPreviousZero(nums, nums.size() - 1);
        while (left < right) {
            swapAndUpdateIndexes(nums, left, right);
        }
    }

    void swapAndUpdateIndexes(vector<int>& nums, int& left, int& right) {
        swap(nums[left], nums[right]);
        left = findNextOne(nums, left);
        right = findPreviousZero(nums, right);
    }

    int findNextOne(const vector<int>& nums, int left) {
        while(left < nums.size() && nums[left] == 0) {
            left++;
        }
        return left;
    }

    int findPreviousZero(const vector<int>& nums, int right) {
        while(0 <= right && nums[right] == 1) {
            right--;
        }
        return right;
    }

    void swap(int& num1, int& num2) {
        int aux = num1;
        num1 = num2;
        num2 = aux;
    }
};
