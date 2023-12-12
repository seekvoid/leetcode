#include <string>

using namespace std;

// https://leetcode.cn/leetbook/read/array-and-string/conm7/
/*
    从最大长度开始遍历，比较原字符串与reverse后的字符串，符合则返回
*/

// 暴力求解，O(n^3), 超时hhhh, 寄
// class Solution {
// public:
//     string longestPalindrome(string s) {

//         string tmp;
//         string res = "";
//         int len = 0;

//         for (int i=0; i<s.length(); i++){
//             for (int j=s.length()-i; j >0; j--){
//                 tmp = s.substr(i, j);
//                 reverse(tmp.begin(), tmp.end());

//                 if (tmp == s.substr(i, j) && j > len){
//                     len = j;
//                     res = s.substr(i, j);
//                 }

//             }
//         }
//         return res;
//     }
// };

// 中心扩展法
// 选择一个中心向两边扩展比较
// O(n^2)
class Solution
{
public:
    string longestPalindrome(string s)
    {
        int size = s.size();
        while (size > 1){
            if (size % 2 == 0){
                // even
                for (int index = 0; index+size <= s.size(); index++){
                    if (leven(s,  index+size/2-1, size/2 -1)){
                        return s.substr(index, size);
                    }
                }

            } else {
                // odd
                for (int index=0; index+size <= s.size(); index++){
                    if (lodd(s, index + size/2, size/2)){
                        return s.substr(index, size);
                    }
                }

            }
            size--;
        }

        return s.substr(0,1);
    }

private:
    bool lodd(string &s, int index, int len)
    {
        // 奇数扩展，以index为中心，向左右各扩展len长度，若符合回文则返回true;
        for (int i = 1; i < len + 1; i++)
        {
            if (s[index + i] != s[index - i])
            {
                return false;
            }
        }
        return true;
    }

    bool leven(string &s, int index, int len)
    {
        // 偶数扩展, 以index和index+1为中心，向左右各扩展len长度，若回文则返回true;
        if (s[index] != s[index + 1])
        {
            return false;
        }
        for (int i = 1; i < len + 1; i++)
        {
            if (s[index + i + 1] != s[index - i])
            {
                return false;
            }
        }
        return true;
    }
};

// 第三种思路是动态规划，优化后的穷举hh
// 构建DPtable, O(n^2)
/*  引用

回文串具有如下性质：
如果回文串首字符和尾字符不相等，那么它必然不是回文串;
如果回文串首字符和尾字符相等，那么它是否为回文串由去除首尾字符的字串决定;

因此构造DPTable:
dp[i][j]: 表示s[i...j]之间字串是否为回文串
dp[i][j]=nums[i]==nums[j]&&(dp[i+1][j-1])

*/