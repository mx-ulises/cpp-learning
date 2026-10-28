class Solution {
private:
    bool isBetterBox(int itemSize, int capacity, int minimalCapacity) {
        return itemSize <= capacity && capacity < minimalCapacity;
    }

public:
    int minimumIndex(vector<int>& capacity, int itemSize) {
        int minimalIndex = -1;
        int minimalCapacity = 101;
        for (int i = 0; i < capacity.size(); i++) {
            if (isBetterBox(itemSize, capacity[i], minimalCapacity)) {
                minimalCapacity = capacity[i];
                minimalIndex = i;
            }
        }
        return minimalIndex;
    }
};
