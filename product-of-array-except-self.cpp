class Solution {
public:
    vector<int> productExceptSelf(vector<int>& nums) {
        vector<int> answer(nums.size());
        int leftAccumulator = 1;
        for (int i = 0; i < answer.size(); i++) {
            answer[i] = leftAccumulator;
            leftAccumulator *= nums[i];
        }
        int rightAccumulator = 1;
        for (int i = answer.size() - 1; 0 <= i; i--) {
            answer[i] *= rightAccumulator;
            rightAccumulator *= nums[i];
        }
        return answer;
    }
};
