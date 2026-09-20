class Solution {
private:
    int MAXIMAL_DISTANCE = 1000;

    int getManhattanDistance(int x1, int y1, int x2, int y2) {
        return abs(x1 - x2) + abs(y1 - y2);
    }

    int getDistance(vector<int>& drone, vector<int>& target) {
        int distance = getManhattanDistance(drone[0], drone[1], target[0], target[1]);
        if (distance <= drone[2]) {
            return distance;
        }
        return MAXIMAL_DISTANCE;
    }

public:
    int nearestDrone(vector<vector<int>>& drones, vector<int>& target) {
        int index = -1;
        int minDistance = MAXIMAL_DISTANCE;
        for (int i = 0; i < drones.size(); i++) {
            int candidateDistance = getDistance(drones[i], target);
            if (candidateDistance < minDistance) {
                minDistance = candidateDistance;
                index = i;
            }
        }
        return index;
    }
};
