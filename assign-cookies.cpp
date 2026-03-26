class Solution {
private:
    bool areEnoughChildrenAndCookies(vector<int>& g, vector<int>& s, int contentChildren, int cookiesConsumed) {
        return contentChildren < g.size() && cookiesConsumed < s.size();
    }

    int findCookieForChild(vector<int>& g, vector<int>& s, int contentChildren, int cookiesConsumed) {
        while (cookiesConsumed < s.size() && s[cookiesConsumed] < g[contentChildren]) {
            cookiesConsumed++;
        }
        return cookiesConsumed;
    }

    int updateContentChildrenIfValidCookie(vector<int>& s, int cookiesConsumed, int contentChildren) {
        if (cookiesConsumed < s.size()) {
            contentChildren++;
        }
        return contentChildren;
    }

public:
    int findContentChildren(vector<int>& g, vector<int>& s) {
        sort(g.begin(), g.end());
        sort(s.begin(), s.end());
        int contentChildren = 0;
        int cookiesConsumed = 0;
        while (areEnoughChildrenAndCookies(g, s, contentChildren, cookiesConsumed)) {
            cookiesConsumed = findCookieForChild(g, s, contentChildren, cookiesConsumed);
            contentChildren = updateContentChildrenIfValidCookie(s, cookiesConsumed, contentChildren);
            cookiesConsumed++;
        }
        return contentChildren;
    }
};
