struct SubsetAnalysis {
    int minimal;
    int conjunction;
};

SubsetAnalysis updateSubsetAnalysis(SubsetAnalysis subsetAnalysis, int num) {
    subsetAnalysis.minimal = min(subsetAnalysis.minimal, num);
    subsetAnalysis.conjunction = subsetAnalysis.conjunction & num;
    return subsetAnalysis;
}

bool isSubsetConsistent(SubsetAnalysis subsetAnalysis) {
    return subsetAnalysis.conjunction == subsetAnalysis.minimal;
}

class Solution {
public:
    int countConsistent(vector<int>& nums) {
        int count = 0;
        SubsetAnalysis subsetAnalysis = {0, 0};
        for (int i = 0; i < nums.size(); i++) {
            subsetAnalysis = {nums[i], nums[i]};
            for (int j = i; j < nums.size(); j++) {
                subsetAnalysis = updateSubsetAnalysis(subsetAnalysis, nums[j]);
                if (isSubsetConsistent(subsetAnalysis)) count++;
            }
        }
        return count;
    }
};
