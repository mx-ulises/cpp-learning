class Solution {
public:
    string largestNumber(vector<int>& nums) {
        string output = "";
        vector<string> numStrings(nums.size());
        for (int i = 0; i < nums.size(); i++) {
            numStrings[i] = to_string(nums[i]);
        }
        sort(numStrings.begin(), numStrings.end(), 
             [](const string &a, const string &b) {
                return (a + b) < (b + a);
             });
        for (int i = numStrings.size() - 1; 0 <= i; i--) {
            output += numStrings[i];
        }
        int start = 0;
        while (start < output.size() - 1 && output[start] == '0') {
            start++;
        }
        return output.substr(start);
    }
};
