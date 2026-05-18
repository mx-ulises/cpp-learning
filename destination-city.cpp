class Solution {
public:
    string destCity(vector<vector<string>>& paths) {
        unordered_set<string> hasOutboundFlight;
        for(int i = 0; i < paths.size(); i++) {
            hasOutboundFlight.insert(paths[i][0]);
        }
        for(int i = 0; i < paths.size(); i++) {
            if (hasOutboundFlight.find(paths[i][1]) == hasOutboundFlight.end()) {
                return paths[i][1];
            }
        }
        return "";
    }
};
