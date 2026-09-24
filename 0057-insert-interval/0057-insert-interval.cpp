class Solution {
public:
    vector<vector<int>> insert(vector<vector<int>>& intervals, vector<int>& newInterval) {
        vector<vector<int>> ans;

        int start = newInterval[0];
        int end = newInterval[1];

        int i = 0;
        int n = intervals.size();

        
        while (i < n && intervals[i][1] < start) {
            ans.push_back(intervals[i]);
            i++;
        }

    
        while (i < n && intervals[i][0] <= end) {
            start = min(start, intervals[i][0]);
            end = max(end, intervals[i][1]);
            i++;
        }

    
        ans.push_back({start, end});


        while (i < n) {
            ans.push_back(intervals[i]);
            i++;
        }

        return ans;
    }
};