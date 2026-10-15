class Solution {
public:
    vector<int> scoreValidator(vector<string>& events) {
        unordered_set<string> scoreIncreasers({"WD", "NB"});
        int score = 0;
        int counter = 0;
        for (auto& event : events) {
            if (event == "W") counter++;
            else if (scoreIncreasers.count(event)) score++;
            else score += stoi(event);  
            if (counter == 10)  break;
        }
        return {score, counter};
    }
};
