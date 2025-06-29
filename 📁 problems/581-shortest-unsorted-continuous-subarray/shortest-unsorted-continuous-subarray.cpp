class Solution {
public:
    int findUnsortedSubarray(vector<int>& nums) {
        int n = nums.size();
        int left = 0, right = n - 1;

        while (left < n - 1 && nums[left] <= nums[left + 1])
            left++;

        if (left == n - 1)
            return 0;

        while (right > 0 && nums[right] >= nums[right - 1])
            right--;

        int subarray_min = INT_MAX, subarray_max = INT_MIN;
        for (int i = left; i <= right; ++i) {
            subarray_min = min(subarray_min, nums[i]);
            subarray_max = max(subarray_max, nums[i]);
        }

        while (left > 0 && nums[left - 1] > subarray_min)
            left--;

        while (right < n - 1 && nums[right + 1] < subarray_max)
            right++;

        return right - left + 1;
    }
};
