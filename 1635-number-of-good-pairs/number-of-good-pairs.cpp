class Solution {
public:
    int numIdenticalPairs(vector<int>& nums) {
        int count[101] = {0};
        int result = 0;

        for (int i = 0; i < nums.size(); i++) {
            result += count[nums[i]];
            count[nums[i]]++;
        }

        return result;
    }
};
