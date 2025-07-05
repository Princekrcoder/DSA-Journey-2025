class Solution {
public:
    vector<vector<int>> imageSmoother(vector<vector<int>>& img) {
        int rows = img.size();
        int cols = img[0].size();
        vector<vector<int>> result(rows, vector<int>(cols, 0));

        vector<int> dir = {-1, 0, 1};

        for (int i = 0; i < rows; ++i) {
            for (int j = 0; j < cols; ++j) {
                int sum = 0, count = 0;
                for (int dx : dir) {
                    for (int dy : dir) {
                        int x = i + dx;
                        int y = j + dy;
                        if (x >= 0 && x < rows && y >= 0 && y < cols) {
                            sum += img[x][y];
                            count++;
                        }
                    }
                }
                result[i][j] = sum / count;
            }
        }

        return result;
    }
};
