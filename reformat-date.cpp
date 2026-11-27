class Solution {
private:
    bool isDigit(char c) {
        return '0' <= c && c <= '9';
    }

    string getYear(string date) {
        return date.substr(date.size() - 4, 4);
    }

    string getMonth(string date) {
        string month = date.substr(date.find(' ') + 1, 3);
        if (month == "Jan") return "01";
        if (month == "Feb") return "02";
        if (month == "Mar") return "03";
        if (month == "Apr") return "04";
        if (month == "May") return "05";
        if (month == "Jun") return "06";
        if (month == "Jul") return "07";
        if (month == "Aug") return "08";
        if (month == "Sep") return "09";
        if (month == "Oct") return "10";
        if (month == "Nov") return "11";
        if (month == "Dec") return "12";
        return "00";
    }

    string getDay(string date) {
        string candidate = date.substr(0, 2);
        if (isDigit(candidate[1])) return candidate;
        return "0" + date.substr(0, 1);
    }

public:
    string reformatDate(string date) {
        return getYear(date) + "-" + getMonth(date) + "-" + getDay(date);
    }
};
