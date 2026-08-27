class Solution {
public:
    string lexGreaterPermutation(string s, string target) {
        int n = s.size();
        sort(s.begin(), s.end());

        // Try every position from right to left
        for (int i = n - 1; i >= 0; i--) {
            // We need prefix target[0..i-1]
            int freq[26] = {};

            for (char c : s)
                freq[c - 'a']++;

            bool possible = true;

            // Use target's prefix
            for (int j = 0; j < i; j++) {
                int x = target[j] - 'a';

                if (freq[x] == 0) {
                    possible = false;
                    break;
                }

                freq[x]--;
            }

            if (!possible)
                continue;

            // At position i, choose smallest character > target[i]
            int x = target[i] - 'a';

            for (int c = x + 1; c < 26; c++) {
                if (freq[c] > 0) {
                    string ans = target.substr(0, i);
                    ans += char('a' + c);

                    freq[c]--;

                    // Append remaining chars in sorted order
                    for (int k = 0; k < 26; k++) {
                        ans += string(freq[k], char('a' + k));
                    }

                    return ans;
                }
            }
        }

        return "";
    }
};