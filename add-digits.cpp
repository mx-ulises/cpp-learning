class Solution {
private:
    int updateNum(int num) {
        int aux = 0;
        while (0 < num) {
            aux += num % 10;
            num /= 10;
        }
        return aux;
    }

public:
    int addDigits(int num) {
        while (10 <= num) {
            num = updateNum(num);
        }
        return num;
    }
};
