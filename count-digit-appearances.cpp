class Solution {
private:
    int countDigitOccurrencesInNum(int num, int digit) {
        int digitOcurrences = 0;
        while (0 < num) {
            if (num % 10 == digit) digitOcurrences++;
            num /= 10;
        }
        return digitOcurrences;
    }

public:
    int countDigitOccurrences(vector<int>& nums, int digit) {
        int digitOcurrences = 0;
        for (int num : nums) {
            digitOcurrences += countDigitOccurrencesInNum(num, digit);
        }
        return digitOcurrences;
    }
};
