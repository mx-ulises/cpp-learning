class Solution {
public:
    vector<int> stableMountains(vector<int>& height, int threshold) {
        vector<int>* output = new vector<int>();
        for (int i = 1; i < height.size(); i++) {
            if (threshold < height[i - 1]) {
                output->push_back(i);
            }
        }
        return *output;
    }
};
