#include <vector>
#include <string>

using namespace std;

//https://leetcode.cn/leetbook/read/array-and-string/ceda1/
// O(n^2) / O(n * average_length(n))

class Solution {
public:
    string longestCommonPrefix(vector<string>& strs) {

        string res = strs[0];

        for (int i=1; i < strs.size(); i++){
            int j=0; 
            while (j < min(res.length(), strs[i].length()) && res[j] == strs[i][j]){
                j++;
            }
            res = strs[i].substr(0,j);
        }

        return res;

    }
};