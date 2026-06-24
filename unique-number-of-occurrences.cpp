class Solution {
public:
    bool uniqueOccurrences(vector<int>& arr) {
        unordered_map<int,int> numCount;
        for (int num : arr) {
            numCount[num]++;
        }
        unordered_set<int> counts;
        for (auto [num, count] : numCount) {
            if (counts.find(count) != counts.end()) {
                return false;
            }
            counts.insert(count);
        }
        return true;
    }
};
