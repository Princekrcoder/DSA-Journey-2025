class Solution {
public:
    bool check(vector<int>& nums, int target) {
        bool seen[2] = {false, false};

        for (int x : nums) {
            int p = x % 2;

            // x itself can be used
            if (p == target) {
                seen[p] = true;
            }
            else {
                // Need x - nums[j] to have target parity
                // p ^ (nums[j] % 2) == target
                int required = p ^ target;

                // Need a smaller element of required parity
                if (!seen[required])
                    return false;

                seen[p] = true;
            }
        }

        return true;
    }

    bool uniformArray(vector<int>& nums1) {
        sort(nums1.begin(), nums1.end());

        // Try all odd
        if (check(nums1, 1))
            return true;

        // Try all even
        if (check(nums1, 0))
            return true;

        return false;
    }
};