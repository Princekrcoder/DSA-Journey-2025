class Solution {
public:

    pair<int, int> getInterval(
        string &s,
        int start,
        vector<int> &first,
        vector<int> &last
    ) {
        int end = last[s[start] - 'a'];

        for (int i = start; i <= end; i++) {

            int c = s[i] - 'a';

            // Character ki occurrence substring ke bahar hai
            if (first[c] < start)
                return {-1, -1};

            end = max(end, last[c]);
        }

        return {start, end};
    }

    vector<string> maxNumOfSubstrings(string s) {

        int n = s.size();

        vector<int> first(26, -1);
        vector<int> last(26, -1);

        // First and last occurrence
        for (int i = 0; i < n; i++) {

            int c = s[i] - 'a';

            if (first[c] == -1)
                first[c] = i;

            last[c] = i;
        }

        vector<pair<int,int>> intervals;

        // Generate valid intervals
        for (int c = 0; c < 26; c++) {

            if (first[c] == -1)
                continue;

            int start = first[c];

            auto interval =
                getInterval(s, start, first, last);

            if (interval.first != -1)
                intervals.push_back(interval);
        }

        // Sort by ending position
        sort(intervals.begin(), intervals.end(),
            [](auto &a, auto &b) {
                return a.second < b.second;
            });

        vector<string> ans;

        int prevEnd = -1;

        for (auto &[start, end] : intervals) {

            if (start > prevEnd) {

                ans.push_back(
                    s.substr(start, end - start + 1)
                );

                prevEnd = end;
            }
        }

        return ans;
    }
};