class Solution {
private:
    void getPaths(vector<vector<int>>& graph, vector<vector<int>>& output, vector<int>& current, int start, int end) {
        if (start == end) {
            output.push_back(current);
            return;
        }
        for (int succ : graph[start]) {
            current.push_back(succ);
            getPaths(graph, output, current, succ, end);
            current.pop_back();
        }
    }

public:
    vector<vector<int>> allPathsSourceTarget(vector<vector<int>>& graph) {
        vector<vector<int>> output;
        vector<int> current = {0};
        int target = graph.size() - 1;
        getPaths(graph, output, current, 0, target);
        return output;
    }
};
