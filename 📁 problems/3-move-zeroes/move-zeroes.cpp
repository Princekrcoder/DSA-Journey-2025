class Solution {
public:
    void moveZeroes(vector<int>& nums) {
        int pos = 0;
        for (int i = 0; i < nums.size(); i++) {
            if (nums[i] != 0) {
                swap(nums[i], nums[pos]);
                pos++;
            }
        }

        
        for (int j = 0; j < nums.size(); j++) {
            cout << nums[j] << " ";
        }
    }
};
