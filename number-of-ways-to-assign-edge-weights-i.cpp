
struct Tree {
    vector<Tree*> neighbors;
};

struct TreeHeight {
    Tree* node;
    int h;
};

class Solution {
private:
    Tree* buildTree(vector<vector<int>>& edges) {
        unordered_map<int, Tree*> nodes;
        for (auto& edge: edges) {
            int u = edge[0], v = edge[1];
            nodes.insert({u, new Tree()});
            nodes.insert({v, new Tree()});
            nodes[u]->neighbors.push_back(nodes[v]);
            nodes[v]->neighbors.push_back(nodes[u]);
        }
        return nodes[1];
    }

    int getHeight(Tree* root) {
        unordered_set<Tree*> visited;
        int h = -1;
        queue<TreeHeight> q;
        q.push(TreeHeight{root, 0});
        while (0 < q.size()) {
            TreeHeight nodeHeight = q.front();
            q.pop();
            if (nodeHeight.node == nullptr || visited.find(nodeHeight.node) != visited.end()) {
                continue;
            }
            visited.insert(nodeHeight.node);
            h = max(h, nodeHeight.h);
            for (auto& neighbor : nodeHeight.node->neighbors) {
                q.push(TreeHeight{neighbor, nodeHeight.h + 1});
            }
        }
        return h;
    }

public:
    int assignEdgeWeights(vector<vector<int>>& edges) {
        Tree* root = buildTree(edges);
        int height = getHeight(root);
        long assignations = 1;
        while (1 < height) {
            assignations *= 2;
            assignations %= 1000000007;
            height--;
        }
        return assignations;
    }
};
