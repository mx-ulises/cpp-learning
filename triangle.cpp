struct pair_hash {
    size_t operator()(const pair<int,int>& p) const {
        return std::hash<int>()(p.first) ^ (std::hash<int>()(p.second) << 1);
    }
};

class Solution {
private:
    int minimumTotal(vector<vector<int>>& triangle, int i, int j, unordered_map<pair<int,int>, int, pair_hash>& visited) {
        if (i == triangle.size()) return 0;
        if (visited.find({i, j}) == visited.end()) {
            int left = minimumTotal(triangle, i + 1, j, visited);
            int right = minimumTotal(triangle, i + 1, j + 1, visited);
            visited[{i, j}] = min(left, right) + triangle[i][j];
        }
        return visited[{i, j}];
    }
public:
    int minimumTotal(vector<vector<int>>& triangle) {
        unordered_map<pair<int,int>, int, pair_hash> visited;
        return minimumTotal(triangle, 0, 0, visited);
    }
};
