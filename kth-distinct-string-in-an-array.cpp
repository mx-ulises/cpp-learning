class Solution {
private:
    unordered_map<string,int> getStringOccurrences(vector<string>& arr) const {
        unordered_map<string,int> stringOccurrences;
        for (const auto& s : arr) stringOccurrences[s]++;
        return stringOccurrences;
    }

    string findKthDistinct(vector<string>& arr, unordered_map<string,int>& stringOccurrences, int k) {
        for (const auto& candidate : arr) {
            if (stringOccurrences[candidate] == 1) k--;
            if (k == 0) return candidate;
        }
        return "";
    }

public:
    string kthDistinct(vector<string>& arr, int k) {
        unordered_map<string,int> stringOccurrences = getStringOccurrences(arr);
        return findKthDistinct(arr, stringOccurrences, k);
    }
};
