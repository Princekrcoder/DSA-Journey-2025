class Solution {
public:

    vector<string> ans;

    unordered_map<char, string> mp = {
        {'2',"abc"},
        {'3',"def"},
        {'4',"ghi"},
        {'5',"jkl"},
        {'6',"mno"},
        {'7',"pqrs"},
        {'8',"tuv"},
        {'9',"wxyz"}
    };

    void solve(int index, string &digits, string curr) {
        //base case
        if(index == digits.length()) {
            ans.push_back(curr);
            return;
        }

        char digit = digits[index];

        string letters = mp[digit];

        for(char ch : letters) {
            solve(index + 1, digits, curr + ch);
        }
    }

    vector<string> letterCombinations(string digits) {
        if(digits.empty()) {
            return{};
        }

        solve(0, digits, "");
        return ans;
    }
};