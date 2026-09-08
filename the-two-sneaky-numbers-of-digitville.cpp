class Solution {
public:
    vector<int> getSneakyNumbers(vector<int>& nums) {
        int n = nums.size() - 2;
        int offset = 0;
        for (int i = 0; i < n; i++) {
            while(i != nums[i]) {
                int j = nums[i];
                if (j == nums[j]) {
                    nums[i] = nums[n + offset];
                    nums[n + offset] = j;
                    offset++;
                } else {
                    nums[i] = nums[j];
                    nums[j] = j;
                }
            }
        }
        return {nums[n], nums[n + 1]};
    }
};
