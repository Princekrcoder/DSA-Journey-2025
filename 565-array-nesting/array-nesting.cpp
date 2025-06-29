class Solution {
public:
    int arrayNesting(vector<int>& nums) {
        int maxLen = 0;
        int n = nums.size();
        
        for (int i = 0; i < n; ++i) {
            if (nums[i] != -1) {
                int start = i;
                int count = 0;
                while (nums[start] != -1) {
                    int temp = start;
                    start = nums[start];
                    nums[temp] = -1;
                    ++count;
                }
                maxLen = max(maxLen, count);
            }
        }
        
        return maxLen;
    }
};
