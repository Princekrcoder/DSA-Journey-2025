class Solution {
public:
    vector<vector<int>> merge(vector<vector<int>>& intervals) {
        vector<vector<int>> merged;

        if (intervals.empty())
            return merged;

        
        sort(intervals.begin(), intervals.end());

        
        merged.push_back(intervals[0]);

        for (int i = 1; i < intervals.size(); i++) {
            int lastEnd = merged.back()[1];
            int currentStart = intervals[i][0];
            int currentEnd = intervals[i][1];

            if (currentStart <= lastEnd) {
                
                merged.back()[1] = max(lastEnd, currentEnd);
            } else {
                
                merged.push_back(intervals[i]);
            }
        }

        return merged;
    }
};
