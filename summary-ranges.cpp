class Solution {
private:
    void addSummary(vector<string>& summary, int start, int end) {
    if (start != end) {
        summary.push_back(format("{}->{}", start, end));
    } else {
        summary.push_back(format("{}", start));
    }
}

public:
    vector<string> summaryRanges(vector<int>& nums) {
        if (nums.size() == 0) return {};
        int start = nums[0];
        int prev = nums[0];
        vector<string> summary;
        for (int i = 1; i < nums.size(); i++) {
            if ((prev + 1) != nums[i]) {
                addSummary(summary, start, prev);
                start = nums[i];
            }
            prev = nums[i];
        }
        addSummary(summary, start, prev);
        return summary;
    }
};
