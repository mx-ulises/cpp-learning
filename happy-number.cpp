class Solution {
private:
    int updateNumber(int n) {
        int candidate = 0;
        while (n != 0) {
            int d = n % 10;
            candidate += d * d;
            n /= 10;
        }
        return candidate;
    }

public:
    bool isHappy(int n) {
       unordered_set<int> visited;
       while (visited.count(n) == 0) {
          visited.insert(n);
          n = updateNumber(n);
          if (n == 1) return true;
       }
       return false; 
    }
};
