class Solution {
private:
    int isJewelIndex(char c) {
        return c - 'A';
    }

    vector<bool> getIsJewel(string & jewels) {
        vector<bool> isJewel(isJewelIndex('z') + 1);
        for (char jewel: jewels) {
            isJewel[isJewelIndex(jewel)] = true;
        }
        return isJewel;
    }

    int getNumJewels(vector<bool> & isJewel, string & stones) {
        int numJewels = 0;
        for (char stone: stones) {
            if (isJewel[isJewelIndex(stone)]) {
                numJewels++;
            }
        }
        return numJewels;
    }

public:
    int numJewelsInStones(string jewels, string stones) {
        vector<bool> isJewel = getIsJewel(jewels);
        return getNumJewels(isJewel, stones);
    }
};
