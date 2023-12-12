// https://leetcode.cn/leetbook/read/array-and-string/cuxq3/

// 以 (0,0) (0,1) (1,0) (2,0) (1,1) (0,2) (0,3) (1,2) (2,1) (2,2) (1,3) (2,3)的顺序遍历
// 观察可知x+y的和递增,0,1,2,3,4,5 [1,2,3,3,2,1]
// 根据奇偶次数遍历方向会改变, 具体顺序见原题图

// mxn matrix

// O(n)

#include <vector>

using namespace std;

class Solution {
public:
    vector<int> findDiagonalOrder(vector<vector<int>>& mat) {
        int rown = mat.size();
        int coln = mat[0].size();
        vector<int> res;

        for (int i=0; i < coln+rown-1; i++){
            if (i%2 == 0){
                // 从下往上
                for (int j= min(i,rown-1); j >= 0 && i-j < coln; j--){
                    res.push_back(mat[j][i-j]);
                }
            } else {
                // 从上往下
                for (int j=min(i,coln-1);j>=0 && i-j < rown; j--){
                    res.push_back(mat[i-j][j]);
                }
            }


        }
        

        return res;

    }
};