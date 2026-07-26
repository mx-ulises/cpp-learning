class Solution {
public:
    vector<int> getRow(int rowIndex) {
        vector<int> current({1});
        while(0 < rowIndex) {
            vector<int> succesor;
            succesor.push_back(1);
            for(int i = 1; i < current.size(); i++) {
                succesor.push_back(current[i - 1] + current[i]);
            }
            succesor.push_back(1);
            current = succesor;
            rowIndex--;
        }
        return current;
    }
};
