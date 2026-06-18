class Solution {
private:
    vector<int> records;
    int recordSum;
    int n;

    void addRecord(int record) {
        records.push_back(record);
        recordSum += record;
        n++;
    }

    void removeRecord() {
        recordSum -= records[n - 1];
        records.pop_back();
        n--;
    }

public:
    int calPoints(vector<string>& operations) {
        for (auto& operation : operations) {
            if (operation == "+") addRecord(records[n - 1] + records[n - 2]);
            else if (operation == "D") addRecord(2 * records[n - 1]);
            else if (operation == "C") removeRecord();
            else addRecord(stoi(operation));
        }
        return recordSum;
    }
};
