struct DigitAndCarry{
    int digit;
    int carry;
};

class Solution {
private:
    DigitAndCarry getDigitAndCarry(int digit, int k) {
        int aggregate = digit + k;
        return {aggregate % 10, aggregate / 10};
    }

    int addDigitAndUpdateCarry(int digit, int k, vector<int>& result) {
        DigitAndCarry digitAndCarry = getDigitAndCarry(digit, k);
        result.push_back(digitAndCarry.digit);
        return digitAndCarry.carry;
    }

    int fillResultAndUpdateK(vector<int>& num, int k, vector<int>& result) {
        for (int i = num.size() - 1; 0 <= i; i--) {
            k = addDigitAndUpdateCarry(num[i], k, result);
        }
        return k;
    }

    void fillResultFromK(int k, vector<int>& result) {
        while (0 < k) {
            k = addDigitAndUpdateCarry(0, k, result);
        }
    }

public:
    vector<int> addToArrayForm(vector<int>& num, int k) {
        vector<int> result;
        k = fillResultAndUpdateK(num, k, result);
        fillResultFromK(k, result);
        std::reverse(result.begin(), result.end());
        return result;
    }
};
