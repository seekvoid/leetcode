// https://leetcode.cn/leetbook/read/array-and-string/cxqdh/
#include <vector>

using namespace std;

class Solution {
public:
    int searchInsert(vector<int>& nums, int target) {
        int head = 0;
        int tail = nums.size()-1;

        while (head != tail){
            int pos = (head + tail) / 2;
            if (target == nums[pos]){
                return pos;
            } else if (target < nums[pos]){
                // search left
                tail = pos;
            } else {
                // search right
                head = pos+1;
            }
        }
        // not found
        if (target <= nums[head]){
            return head;
        } else {
            return head+1;
        }
    }
};