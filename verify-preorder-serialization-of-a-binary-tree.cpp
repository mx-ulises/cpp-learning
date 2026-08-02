class Solution {
private:
    int addItems(string& item) {
        if (item != "#") {
            return 2;
        }
        return 0;
    }

public:
    bool isValidSerialization(string preorder) {
        stringstream ss(preorder);
        string item;
        getline(ss, item, ',');
        int s = addItems(item);
        while (getline(ss, item, ',')) {
            if (s == 0) return false;
            s += addItems(item) - 1;
        }
        return s == 0;
    }
};
