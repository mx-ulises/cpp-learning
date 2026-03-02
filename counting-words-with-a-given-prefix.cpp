class Solution {
private:
    bool startWith(string& word, string& pref) {
        if (word.size() < pref.size())
            return false;
        for (int i = 0; i < pref.size(); i++)
            if (pref[i] != word[i])
                return false;
        return true;
    }

public:
    int prefixCount(vector<string>& words, string pref) {
        int count = 0;
        for (auto word : words) {
            if (startWith(word, pref))
                count++;
        }
        return count;
    }
};
