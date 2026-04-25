class Solution {
private:
    void getNumCount(vector<int>& numCount, const vector<int>& nums) {
        for (auto num : nums) numCount[num + 10]++;
    }

    void getSubsets(vector<vector<int>>& subsets, vector<int>& numCount, vector<int>& current, int i) {
        if (numCount.size() == i) {
            subsets.push_back(current);
            return;
        }
        int count = numCount[i], num = i - 10;
        i++;
        getSubsets(subsets, numCount, current, i);
        for (int j = 0; j < count; j++) {
            current.push_back(num);
            getSubsets(subsets, numCount, current, i);
        }
        for (int j = 0; j < count; j++) {
            current.pop_back();
        }
    }

public:
    vector<vector<int>> subsetsWithDup(vector<int>& nums) {
        vector<int> numCount(21);
        getNumCount(numCount, nums);
        vector<vector<int>> subsets({});
        vector<int> current({});
        getSubsets(subsets, numCount, current, 0);
        return subsets;
    }
};
