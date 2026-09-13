class Solution {
public:
    bool isPalindrome(string s) {
        int n = s.size();
        vector<char> ans;
        for(int i = 0; i < n; i++) {
            if((s[i]>='a' && s[i] <='z') || (s[i]>='A' && s[i] <= 'Z')){
                ans.push_back(tolower(s[i]));
            }
            if(s[i] >= '0' && s[i]<='9'){
                ans.push_back(s[i]);
            }
        }
        int back = ans.size()-1;
        int st = 0;
        bool palindrome = true;
        while(st<=back){
            if(ans[st] != ans[back]) {
                palindrome = false;
                return palindrome;
            }
            back--;
            st++;
        }
        return palindrome;
    }
};