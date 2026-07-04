/*
// Definition for a QuadTree node.
class Node {
public:
    bool val;
    bool isLeaf;
    Node* topLeft;
    Node* topRight;
    Node* bottomLeft;
    Node* bottomRight;
    
    Node() {
        val = false;
        isLeaf = false;
        topLeft = NULL;
        topRight = NULL;
        bottomLeft = NULL;
        bottomRight = NULL;
    }
    
    Node(bool _val, bool _isLeaf) {
        val = _val;
        isLeaf = _isLeaf;
        topLeft = NULL;
        topRight = NULL;
        bottomLeft = NULL;
        bottomRight = NULL;
    }
    
    Node(bool _val, bool _isLeaf, Node* _topLeft, Node* _topRight, Node* _bottomLeft, Node* _bottomRight) {
        val = _val;
        isLeaf = _isLeaf;
        topLeft = _topLeft;
        topRight = _topRight;
        bottomLeft = _bottomLeft;
        bottomRight = _bottomRight;
    }
};
*/

class Solution {
private:
    bool allLeaves(Node* topLeft, Node* topRight, Node* bottomLeft, Node* bottomRight) {
        bool areAllLeaves = topLeft->isLeaf;
        areAllLeaves &= topRight->isLeaf;
        areAllLeaves &= bottomLeft->isLeaf;
        areAllLeaves &= bottomRight->isLeaf;
        return  areAllLeaves;
    }

    bool allSameValue(Node* topLeft, Node* topRight, Node* bottomLeft, Node* bottomRight) {
        bool areAllSameValue = topLeft->val == topRight->val;
        areAllSameValue &= topLeft->val == bottomLeft->val;
        areAllSameValue &= topLeft->val == bottomRight->val;
        return areAllSameValue;
    }

    bool canMerge(Node* topLeft, Node* topRight, Node* bottomLeft, Node* bottomRight) {
        bool areAllLeaves = allLeaves(topLeft, topRight, bottomLeft, bottomRight);
        bool areAllSameValue = allSameValue(topLeft, topRight, bottomLeft, bottomRight);
        return areAllLeaves && areAllSameValue;
    }

    Node* constructQuadTree(vector<vector<int>>& grid, int offset, int x, int y) {
        if (offset == 0) {
            return new Node(grid[x][y], true);
        }
        int newX = x + offset;
        int newY = y + offset;
        offset >>= 1;
        Node* topLeft = constructQuadTree(grid, offset, x, y);
        Node* topRight = constructQuadTree(grid, offset, x, newY);
        Node* bottomLeft = constructQuadTree(grid, offset, newX, y);
        Node* bottomRight = constructQuadTree(grid, offset, newX, newY);
        if (canMerge(topLeft, topRight, bottomLeft, bottomRight)) {
            return new Node(topLeft->val, true);
        }
        return new Node(1, false, topLeft, topRight, bottomLeft, bottomRight);
    }

public:
    Node* construct(vector<vector<int>>& grid) {
        int offset = grid.size() >> 1;
        return constructQuadTree(grid, offset, 0, 0);
    }
};
