struct HeightPointers {
    int left;
    int right;
};

class Solution {
public:
    int maxArea(vector<int>& height) {
        HeightPointers heightPointers = {0, int(height.size()) - 1};
        int maximalArea = 0;
        while(heightPointers.left < heightPointers.right) {
            int candidateArea = getCandidateArea(height, heightPointers.left, heightPointers.right);
            maximalArea = std::max(maximalArea, candidateArea);
            updateHeightPointers(&heightPointers, height);
        }
        return maximalArea;
    }

    int getCandidateArea(vector<int>& height, int left, int right) {
            int candidateHeight = std::min(height[left], height[right]);
            int candidateLength = right - left;
            return candidateHeight * candidateLength;
    }

    void updateHeightPointers(HeightPointers *heightPointers, vector<int>& height) {
        if(height[heightPointers->left] < height[heightPointers->right]) {
            heightPointers->left++;
        } else {
            heightPointers->right--;
        }
    }
};