//https://leetcode.cn/leetbook/read/array-and-string/c5tv3/
#include <vector>

using namespace std;

class Solution {
public:
    vector<vector<int>> merge(vector<vector<int>>& intervals) {
        if (intervals.size() == 1){
            return intervals;
        }
        
        // sort
        sort(intervals.begin(),intervals.end());

        vector<vector<int>> res;

        res.push_back(intervals[0]);
        int cnt = 0;
        for (int i=1; i<intervals.size(); i++){
            if (res[cnt][1] >= intervals[i][0]){
                // 合并
                res[cnt][1] = max(res[cnt][1],intervals[i][1]); 
            } else {
                // pass
                cnt += 1;
                res.push_back(intervals[i]);
            }
        }

        return res;

    }
};