class Solution {
public:
    string shortestBeautifulSubstring(string s, int k) {
        int n = s.size();
        int left = 0;
        int ones = 0;
        
        string ans = "";
        int bestLen = INT_MAX;

        for (int right = 0; right < n; right++) {
            if (s[right] == '1')
                ones++;

            // Window has exactly k ones
            while (ones == k) {
                // Remove leading zeroes.
                // This makes the substring as short as possible.
                while (left <= right && s[left] == '0') {
                    left++;
                }

                int len = right - left + 1;

                if (len < bestLen) {
                    bestLen = len;
                    ans = s.substr(left, len);
                }
                else if (len == bestLen) {
                    ans = min(ans, s.substr(left, len));
                }

                // Move left past one '1'
                if (s[left] == '1')
                    ones--;

                left++;
            }
        }

        return ans;
    }
};