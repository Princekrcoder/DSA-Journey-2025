class Solution {
public:
    char findTheDifference(string s, string t) {
        string st;
        string st1;
        if(s.size() > t.size()){
            st = s;
            st1 = t;
        }else{
            st = t;
            st1 = s;
        }

        unordered_map<char, int> mp;

        for(int i = 0; i < st.size(); i++) {
            mp[st[i]]++;
        }
        for(int i = 0; i < st1.size(); i++) {
            mp[st1[i]]--;
        }
        char ans;
        for(auto it : mp){
            if(it.second > 0){
                ans = it.first;
                
            }
        }
        return ans;
    }
};