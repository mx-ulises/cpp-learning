class Solution {
private:
    void initializeAnswer(vector<int>& answer) {
        for (int i = 0; i < answer.size(); i++) {
            answer[i] = 100000;
        }
    }

    void passLeftToRight(vector<int>& answer, string& s, char c) {
        int left = 0;
        for(int right = 0; right < s.size(); right++) {
            while (s[right] == c && left <= right) {
                answer[left] = min(answer[left], right - left);
                left++;
            }
        }
    }

    void passRightToLeft(vector<int>& answer, string& s, char c) {
        int right = s.size() - 1;
        for(int left = s.size() - 1; 0 <= left; left--) {
            while(s[left] == c && left <= right) {
                answer[right] = min(answer[right], right - left);
                right--;
            }
        }
    }
public:
    vector<int> shortestToChar(string s, char c) {
        vector<int> answer(s.size());
        initializeAnswer(answer);
        passLeftToRight(answer, s, c);
        passRightToLeft(answer, s, c);
        return answer;
    }
};
