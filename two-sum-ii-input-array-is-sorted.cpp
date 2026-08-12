struct BinarySearchResult {
    bool found;
    int index;
};

class Solution {
private:
    BinarySearchResult binarySearchIndex(vector<int>& numbers, int start, int end, int number) {
        while (start <= end) {
            int mid = (start + end) / 2;
            if (numbers[mid] == number) return {true, mid};
            if (numbers[mid] < number) start = mid + 1;
            else end = mid - 1;
        }
        return {false, 0};
    }

public:
    vector<int> twoSum(vector<int>& numbers, int target) {
        for (int i = 1; i < numbers.size(); i++) {
            int number = target - numbers[i];
            if (number <= numbers[i]) {
                BinarySearchResult result = binarySearchIndex(numbers, 0, i - 1, number);
                if (result.found) {
                    return {result.index + 1, i + 1};
                }
            }
        }
        return {};
    }
};
