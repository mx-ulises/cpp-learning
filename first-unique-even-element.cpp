class Solution {
private:
    void fillNumCount(vector<int>& nums, vector<int>& numCount) {
        for (int num: nums) {
            numCount[num]++;
        }
    }

    bool isUnique(vector<int>& numCount, int num) {
        return numCount[num] == 1;
    }

    bool isEven(int num) {
        return (num & 1) == 0;
    }

public:
    int firstUniqueEven(vector<int>& nums, vector<int>& numCount) {
        for (int num: nums) {
            if (isUnique(numCount, num) && isEven(num)) {
                return num;
            }
        }
        return -1;
    }

    int firstUniqueEven(vector<int>& nums) {
        vector<int> numCount(101);
        fillNumCount(nums, numCount);
        return firstUniqueEven(nums, numCount);
    }
};
