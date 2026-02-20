class Solution {
public:
    vector<int> findArray(vector<int>& pref) {
        vector<int> arr(pref.size());
        int current = 0;
        for (int i = 0; i < pref.size(); i++) {
            arr[i] = current ^ pref[i];
            current ^= arr[i];
        }
        return arr;
    }
};
