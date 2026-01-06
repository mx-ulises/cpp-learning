class Solution {
public:
    string reversePrefix(string word, char ch) {
        int indexOfCh = getIndexOf(word, ch);
        return reverseSubstring(word, 0, indexOfCh);
    }

    int getIndexOf(string word, char ch) {
        for(int i = 0; i < word.size(); i++) {
            if (word[i] == ch) {
                return i;
            }
        }
        return -1;
    }

    string reverseSubstring(string word, int start, int end) {
        while (start < end) {
            word = swapCharacters(word, start, end);
            start++;
            end--;
        }
        return word;
    }

    string swapCharacters(string word, int start, int end) {
        char aux = word[start];
        word[start] = word[end];
        word[end] = aux;
        return word;
    }
};
