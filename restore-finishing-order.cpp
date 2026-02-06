class Solution {
private:
    bool isFriend(vector<int>& friends, int participant) {
        int l = 0;
        int r = friends.size() - 1;
        while (l <= r) {
            int m = (l + r) / 2;
            if (friends[m] == participant) {
                return true;
            } else if (friends[m] < participant) {
                l = m + 1;
            } else {
                r = m - 1;
            }
        }
        return false;
    }

public:
    vector<int> recoverOrder(vector<int>& order, vector<int>& friends) {
        vector<int> friendsOrder(friends.size());
        int i = 0;
        for (int participant : order) {
            if (isFriend(friends, participant)) {
                friendsOrder[i] = participant;
                i++;
            }
        }
        return friendsOrder;
    }
};
