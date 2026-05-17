class Solution {
private:
    bool isValidProduct(int wordCode1, int wordCode2) {
        return (wordCode1 & wordCode2) == 0;
    }

    int getWordCode(string& word) {
        int wordCode = 0;
        for (char c : word) {
            wordCode |= 1 << (c - 'a');
        }
        return wordCode;
    }

    void fillWordCodes(vector<string>& words, vector<int>& wordCodes) {
        for (int i = 0; i < words.size(); i++) {
            wordCodes[i] = getWordCode(words[i]);
        }
    }

    int checkAndUpdateProducts(int wordCode1, int wordSize1, int wordCode2, int wordSize2, int product) {
        if (isValidProduct(wordCode1, wordCode2)) {
            int newProduct = wordSize1 * wordSize2;
            if (product < newProduct) {
                product = newProduct;
            }
        }
        return product;
    }

public:
    int maxProduct(vector<string>& words) {
        int product = 0;
        vector<int> wordCodes(words.size());
        fillWordCodes(words, wordCodes);
        for (int i = 0; i < words.size(); i++) {
            for (int j = i + 1; j < words.size(); j++) {
                product = checkAndUpdateProducts(wordCodes[i], words[i].size(), wordCodes[j], words[j].size(), product);
            }
        }
        return product;
    }
};
