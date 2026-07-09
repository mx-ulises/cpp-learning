class Solution {
private:
    void normalize(vector<int>& nums) {
        for (int i = 0; i < nums.size(); i++) {
            nums[i]--;
        }
    }

    bool isRightPlaced(int num, int position) {
        return num == -1 || num == position;
    }

    bool isDuplicate(int num1, int num2) {
        return num1 == num2;
    }

    void swap(vector<int>& nums, int i, int j) {
        int aux = nums[i];
        nums[i] = nums[j];
        nums[j] = aux;
    }

public:
    vector<int> findDuplicates(vector<int>& nums) {
        normalize(nums);
        vector<int> duplicates;
        int i = 0;
        while (i < nums.size()) {
            while (!isRightPlaced(nums[i], i) && !isDuplicate(nums[i], nums[nums[i]])) {
                swap(nums, i, nums[i]);
            }
            if (!isRightPlaced(nums[i], i) && isDuplicate(nums[i], nums[nums[i]])) {
                duplicates.push_back(nums[i] + 1);
                nums[i] = -1;
            }
            i++;
        }
        return duplicates;
    }
};
