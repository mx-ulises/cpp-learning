struct State {
    int jumps;
    int position;
};

class Solution {
private:
    State getFront(deque<State>& dq) {
        State s = dq[0];
        dq.pop_front();
        return s;
    }

    void fillDequeue(deque<State>& dq, State s, int targetPosition, int jumpLen) {
        s.jumps++;
        while(jumpLen) {
            int newPosition = s.position + jumpLen;
            if (newPosition <= targetPosition) {
                dq.push_back({s.jumps, newPosition});
            }
            jumpLen--;
        }
    }

public:
    int jump(vector<int>& nums) {
        deque<State> dq{{0, 0}};
        int targetPosition = nums.size() - 1, jumpLen, newPosition;
        unordered_set<int> visited;
        State s;
        while (dq.size()) {
            s = getFront(dq);
            if (visited.find(s.position) != visited.end()) {
                continue;
            }
            visited.insert(s.position);
            if (s.position == targetPosition) {
                return s.jumps;
            }
            fillDequeue(dq, s, targetPosition, nums[s.position]);
        }
        return -1;
    }
};
