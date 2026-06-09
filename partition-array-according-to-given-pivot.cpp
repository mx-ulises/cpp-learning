bool less_than(int a, int b) {
    return a < b;
}

bool greater_than(int a, int b) {
    return b < a;
}

bool equal(int a, int b) {
    return a == b;
}

class Solution {
private:
    int fillPivotArray(const vector<int>& nums, int pivot, vector<int>& output, int i, bool (*cmp)(int, int)) {
        for (int num : nums) {
            if (cmp(num, pivot)) {
                output[i] = num;
                i++;
            }
        }
        return i;
    }

public:
    vector<int> pivotArray(vector<int>& nums, int pivot) {
        vector<int> output(nums.size());
        int i = 0;
        i = fillPivotArray(nums, pivot, output, i, less_than);
        i = fillPivotArray(nums, pivot, output, i, equal);
        i = fillPivotArray(nums, pivot, output, i, greater_than);
        return output;
    }
};
