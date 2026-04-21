class Solution {
public:
    vector<int> countBits(int n) {
        vector<int> output(n + 1);
        int j, k, count;
        for (int i = 0; i < n; i++) {
            j = i << 1;
            k = j + 1;
            count = output[i];
            if (j <= n) output[j] = output[i];
            if (k <= n) output[k] = output[i] + 1;
        }
        return output;
    }
};
