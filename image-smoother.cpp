class Solution {
private:
    int min(int x, int y) {
        if (x < y) return x;
        return y;
    }

    int max(int x, int y) {
        if (x < y) return y;
        return x;
    }

    int smoothPixel(vector<vector<int>>& img, int x, int y) {
        int m = img.size(), n = img[x].size();
        int pixelCount = 0, pixelSum = 0;
        int iMinBound = max(x - 1, 0), iMaxBound = min(x + 1, m - 1);
        int jMinBound = max(y - 1, 0), jMaxBound = min(y + 1, n - 1);
        for (int i = iMinBound; i <= iMaxBound; i++) {
            for (int j = jMinBound; j <= jMaxBound; j++) {
                pixelSum += img[i][j];
                pixelCount++;
            }
        }
        return pixelSum / pixelCount;
    }

public:
    vector<vector<int>> imageSmoother(vector<vector<int>>& img) {
        vector<vector<int>> imageSmoothed(img.size());
        for (int i = 0; i < img.size(); i++) {
            imageSmoothed[i] = vector<int>(img[0].size());
            for (int j = 0; j < img[i].size(); j++) {
                imageSmoothed[i][j] = smoothPixel(img, i, j);
            }
        }
        return imageSmoothed;
    }
};
