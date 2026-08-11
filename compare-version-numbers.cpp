class Version {
    private:
    vector<int> versionArray;

    public:
    bool isValidSubVersionIndex(int i) {
        return i < versionArray.size();
    }

    int subVersionValue(int i) {
        if (i < versionArray.size()) {
            return versionArray[i];
        }
        return 0;
    }

    Version(string version) {
        string subversion = "";
        for (char c : version) {
            if (c == '.') {
                versionArray.push_back(stoi(subversion));
                subversion = "";
            } else {
                subversion += c;
            }
        }
        versionArray.push_back(stoi(subversion));
    }
};

class Solution {
public:
    int compareVersion(string version1, string version2) {
        Version v1(version1);
        Version v2(version2);
        int i = 0;
        while (v1.isValidSubVersionIndex(i) || v2.isValidSubVersionIndex(i)) {
            if (v1.subVersionValue(i) < v2.subVersionValue(i)) {
                return -1;
            } else if (v2.subVersionValue(i) < v1.subVersionValue(i)) {
                return 1;
            }
            i++;
        }
        return 0;
    }
};
