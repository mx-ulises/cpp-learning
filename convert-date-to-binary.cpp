struct DateInts {
    int year;
    int month;
    int day;
};

class Solution {
private:
    DateInts getDateInts(string date) {
        return {
            stoi(date.substr(0, 4)),
            stoi(date.substr(5, 2)),
            stoi(date.substr(8, 2))
        };
    }

    char getFirstBitChar(int x) {
        return '0' + (x & 1);
    }

    string getBinStr(int x) {
        string s = "";
        while (0 < x) {
            s += getFirstBitChar(x);
            x >>= 1;
        }
        reverse(s.begin(), s.end());
        return s;
    }

public:
    string convertDateToBinary(string date) {
        DateInts dateInt = getDateInts(date);
        return getBinStr(dateInt.year) + "-"
               + getBinStr(dateInt.month) + "-"
               + getBinStr(dateInt.day);
    }
};
