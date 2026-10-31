class Solution {
private:
    void fillBulbStatus(vector<int>& bulbs, vector<bool>& isBulbOn) {
        for (int bulb: bulbs) {
            isBulbOn[bulb - 1] = !isBulbOn[bulb - 1];
        }
    }

    void fillOutput(vector<bool>& isBulbOn, vector<int>& output) {
        for (int i = 0; i < 100; i++) {
            if (isBulbOn[i]) {
                output.push_back(i + 1);
            }
        }
    }

public:
    vector<int> toggleLightBulbs(vector<int>& bulbs) {
        vector<bool> isBulbOn(100);
        fillBulbStatus(bulbs, isBulbOn);
        vector<int> output;
        fillOutput(isBulbOn, output);
        return output;
    }
};
