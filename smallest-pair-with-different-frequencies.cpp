class Solution {
private:
    const int MAX_NUM = 101;

    void fillNumFrequencies(unordered_map<int,int>& numFrequencies, vector<int>& nums) {
        for (int num: nums) {
            numFrequencies[num]++;
        }
    }

    void fillFrequenciesMinNum(unordered_map<int,int>& frequenciesMinNum, unordered_map<int,int>& numFrequencies) {
        for (const auto& [num, frequency] : numFrequencies) {
            if (frequenciesMinNum.count(frequency) == 0) {
                frequenciesMinNum[frequency] = num;
            }
            frequenciesMinNum[frequency] = min(frequenciesMinNum[frequency], num);
        }
    }

    vector<int> getMinPair(unordered_map<int,int>& frequenciesMinNum) {
        vector<int> minPair({MAX_NUM, MAX_NUM});
        for (const auto& [frequency, num] : frequenciesMinNum) {
            if (num < minPair[0]) {
                minPair[1] = minPair[0];
                minPair[0] = num;
            } else if (num < minPair[1]) {
                minPair[1] = num;
            }
        }
        if (minPair[1] == MAX_NUM) return {-1, -1};
        return minPair;
    }

public:
    vector<int> minDistinctFreqPair(vector<int>& nums) {
        unordered_map<int,int> numFrequencies;
        fillNumFrequencies(numFrequencies, nums);
        unordered_map<int,int> frequenciesMinNum;
        fillFrequenciesMinNum(frequenciesMinNum, numFrequencies);
        return getMinPair(frequenciesMinNum);
    }
};
