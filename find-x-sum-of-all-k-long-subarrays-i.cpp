struct OcurrenceValuePair {
    int ocurrence;
    int value;
};

struct Compare {
    bool operator()(const OcurrenceValuePair& x, const OcurrenceValuePair& y) const {
        if (x.ocurrence != y.ocurrence)
            return y.ocurrence < x.ocurrence;
        return y.value < x.value;
    }
};

class Solution {
private:
    void checkAndUpdate(unordered_map<int, int>& ocurrence, int num) {
        if (ocurrence.count(num) == 0) ocurrence[num] = 0;
        ocurrence[num]++;
    }

    int getMostFrquentSum(unordered_map<int, int>& ocurrence, int x) {
        priority_queue<OcurrenceValuePair, vector<OcurrenceValuePair>, Compare> heap;
        for (const auto& [value, ocurrence] : ocurrence) {
            heap.push({ocurrence, value});
            if (x < heap.size()) heap.pop();
        }
        int sum = 0;
        while (0 < heap.size()) {
            sum += heap.top().ocurrence * heap.top().value;
            heap.pop();
        }
        return sum;
    }

public:
    vector<int> findXSum(vector<int>& nums, int k, int x) {
        unordered_map<int, int> ocurrence;
        for (int i = 0; i < k; i++) {
            checkAndUpdate(ocurrence, nums[i]);
        }
        vector<int> ans;
        ans.push_back(getMostFrquentSum(ocurrence, x));
        for (int i = k; i < nums.size(); i++) {
            ocurrence[nums[i - k]]--;
            checkAndUpdate(ocurrence, nums[i]);
            ans.push_back(getMostFrquentSum(ocurrence, x));
        }
        return ans;
    }
};
