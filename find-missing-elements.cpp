class Solution {
private:
    int getMissingElementsCount(vector<int>& nums) {
        int smallest = nums[0];
        int largest = nums[nums.size() - 1];
        return largest - smallest + 1 - nums.size();
    }

    int addAndMove(vector<int>& output, int start, int end, int i) {
        while(start <= end) {
            output[i] = start;
            start++;
            i++;
        }
        return i;
    }

public:
    vector<int> findMissingElements(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        vector<int> output(getMissingElementsCount(nums));
        int j = 0;
        for(int i = 1; i < nums.size(); i++) {
            j = addAndMove(output, nums[i - 1] + 1, nums[i] - 1, j);
        }
        return output;
    }
};
