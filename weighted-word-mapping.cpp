class Solution {
private:
    int getWordWeight(const string& word, const vector<int>& weights) {
        int wordWeight = 0;
        for (char c : word) {
            int charIndex = c - 'a';
            wordWeight += weights[charIndex];
        }
        return wordWeight;
    }

    char getWeightedCharacter(const string& word, const vector<int>& weights) {
        int wordWeight = getWordWeight(word, weights);
        char weightedCharacter = 'z' - (wordWeight % 26);
        return weightedCharacter;
    }

public:
    string mapWordWeights(vector<string>& words, vector<int>& weights) {
        string output = "";
        for (const auto& word : words) {
            output += getWeightedCharacter(word, weights);
        }
        return output;
    }
};
