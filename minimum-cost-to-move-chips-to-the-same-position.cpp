class Solution {
public:
    int minCostToMoveChips(vector<int>& position) {
        int coinsInOddPosition = 0;
        int coinsInEvenPosition = 0;
        for (int i = 0; i < position.size(); i++) {
            if ((position[i] & 1 ) == 1) {
                coinsInOddPosition++;
            } else {
                coinsInEvenPosition++;
            }
        }
        return min(coinsInOddPosition, coinsInEvenPosition);
    }
};
