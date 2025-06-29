class Solution {
public:
    vector<int> constructArray(int n, int k) {
        vector<int> result;
        int left = 1, right = k + 1;
        while (left <= right) {
            if (left == right) {
                result.push_back(left++);
            } else {
                result.push_back(left++);
                result.push_back(right--);
            }
        }
        for (int i = k + 2; i <= n; ++i) {
            result.push_back(i);
        }
        return result;
    }
};
