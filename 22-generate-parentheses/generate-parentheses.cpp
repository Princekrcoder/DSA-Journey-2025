class Solution {
public:
    vector<string> ans;

    void solve(string curr, int open, int close, int n){
        //Base Case
        if(curr.length() == 2 * n){
            ans.push_back(curr);
            return;
        }

        //add '('
        if(open < n){
            solve(curr + "(", open + 1, close, n);
        }

        //add ')'
        if(close < open){
            solve(curr + ")", open, close + 1, n);
        }
    }

    vector<string> generateParenthesis(int n) {
        solve("", 0, 0, n);
        return ans;
    }
};