class Solution {
public:
    bool isIsomorphic(string s, string t) {
        if (s.size() != t.size()) return false;

        unordered_map<char, char> mp1;
        unordered_map<char, char> mp2;

        for (int i = 0; i < s.size(); i++) {

            char c1 = s[i];
            char c2 = t[i];

            // Mapping already exists
            if (mp1.count(c1)) {
                if (mp1[c1] != c2)
                    return false;
            }
            else {
                mp1[c1] = c2;
            }

            // Reverse mapping
            if (mp2.count(c2)) {
                if (mp2[c2] != c1)
                    return false;
            }
            else {
                mp2[c2] = c1;
            }
        }

        return true;
    }
};