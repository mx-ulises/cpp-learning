enum CharacterType {
    Lowercase,
    Special
};

class Solution {
private:
    bool isLowercase(char c) {
        return 'a' <= c && c <= 'z';
    }

    bool isType(char c, CharacterType characterType) {
        if (characterType == Lowercase) return isLowercase(c);
        return !isLowercase(c);
    }

    int moveLeft(int left, int right, string& s, CharacterType characterType) {
        while(left < right && !isType(s[left], characterType)) {
            left++;
        }
        return left;
    }

    int moveRight(int left, int right, string& s, CharacterType characterType) {
        while(left < right && !isType(s[right], characterType)) {
            right--;
        }
        return right;
    }

    void swapCharacters(int left, int right, string& s) {
        char aux = s[left];
        s[left] = s[right];
        s[right] = aux;
    }

    void reverseCharacterByType(string& s, CharacterType characterType) {
        int left = 0;
        int right = s.size() - 1;
        while (left < right) {
            left = moveLeft(left, right, s, characterType);
            right = moveRight(left, right, s, characterType);
            if (left < right) {
                swapCharacters(left, right, s);
            }
            left++;
            right--;
        }
    }

public:
    string reverseByType(string s) {
        reverseCharacterByType(s, Lowercase);
        reverseCharacterByType(s, Special);
        return s;
    }
};
