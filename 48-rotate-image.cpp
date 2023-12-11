// https://leetcode-cn.com/problems/rotate-image/
#include <vector>

using namespace std;

// O(n)
class Solution
{
public:
    void rotate(vector<vector<int>> &matrix)
    {
        /* input:
            题目限制是NxN矩阵，不用考虑非方阵
            [1 2 3]
            [4 5 6]
            [7 8 9]


            output:
            [7 4 1]
            [8 5 2]
            [9 6 3]
        */
        int row = matrix.size();
        int col = matrix[0].size();

        /* 沿对角线翻转(转置)
            [1 4 7]
            [2 5 8]
            [3 6 9]
        */
        for (int i = 0; i < row; i++)
        {
            for (int j = i + 1; j < col; j++)
            {
                swap(matrix[i][j], matrix[j][i]);
            }
        }

        /* 水平翻转
             [7 4 1]
             [8 5 2]
             [9 6 3]
        */
        for(auto& r: matrix){
            reverse(r.begin(), r.end());
        }
    }
};

// 方法2
// 旋转其实是四个位置的互换，找到互换的数学关系，遍历1/4个矩阵完成交换
// https://zhuanlan.zhihu.com/p/129333223
// O(n)