class Solution {
public:
    int elevatorRequests(int n, vector<int>& requests) {
        int time = 0;
        int currentFloor = 0;
        for (int nextFloor : requests) {
            time += abs(currentFloor - nextFloor);
            currentFloor = nextFloor;
        }
        return time;
    }
};
