class Solution {
public:
    int countMatches(vector<vector<string>>& items, string ruleKey, string ruleValue) {
        int keyIndex = 0;
        if (ruleKey == "color") keyIndex = 1;
        else if (ruleKey == "name") keyIndex = 2;

        int count = 0;
        for (auto& item : items) {
            if (item[keyIndex] == ruleValue) {
                count++;
            }
        }
        return count;
    }
};
