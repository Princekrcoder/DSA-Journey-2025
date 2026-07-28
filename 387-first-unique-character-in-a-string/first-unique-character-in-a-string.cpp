class Solution {
public:
    int firstUniqChar(string s) {
        int ans = -1;
        char c;
        unordered_map<char, int> mpp;

        for(int i = 0; i<s.size(); i++) {
            mpp[s[i]]++;
        }

        for(int i = 0; i < s.size(); i++) {
            if(mpp[s[i]] == 1) {
                return i;
            }
        }

        return ans;
    }
};