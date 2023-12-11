// https://leetcode.cn/leetbook/read/array-and-string/ciekh/
#include <vector>
#include <unordered_set>
using namespace std;

// tranverse and record all row&col number need to set to 0;
// set 0
// O(n)

class Solution
{
public:
    void setZeroes(vector<vector<int>> &matrix)
    {
        unordered_set<int> row;
        unordered_set<int> col;

        int nrow = matrix.size();
        int ncol = matrix[0].size();

        for (int i = 0; i < nrow; i++)
        {
            for (int j = 0; j < ncol;  j++)
            {
                if (matrix[i][j] == 0)
                {
                    if (col.find(j) == col.end())
                    {
                        // mark col
                        col.insert(j);
                    }
                    if (row.find(i) == row.end())
                    {
                        // mark row
                        row.insert(i);
                    }
                }
            }
        }
        for (auto r : row)
        {
            // set row to 0
            for (int i = 0; i < ncol; i++)
            {
                matrix[r][i] = 0;
            }
        }
        for (auto c : col)
        {
            // set col to 0
            for (auto &num : matrix)
            {
                num[c] = 0;
            }
        }
    }
};