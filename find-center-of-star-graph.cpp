class Solution {
public:
    int findCenter(vector<vector<int>>& edges) {
        if (nodeInEdge(edges[0][0], edges[1])) {
            return edges[0][0];
        }
        return edges[0][1];
    }

    bool nodeInEdge(int node, vector<int>& edge) {
        return node == edge[0] || node == edge[1];
    }
};
