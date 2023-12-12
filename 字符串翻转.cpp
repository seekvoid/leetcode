// https://leetcode.cn/leetbook/read/array-and-string/crmp5/

// python版本
// python 万岁

// class Solution:
//     def reverseWords(self, s: str) -> str:
//         a = s.strip().split()
//         a.reverse()
//         return " ".join(a)

#include <vector>
#include <string>

using namespace std;

// O(n)
class Solution {
public:
    string reverseWords(string s) {
        vector<string> l;
        string str;

        // get words
        for (int i = 0; i<s.size(); i++){
            if (s[i] == ' '){
                if (str != ""){
                    l.push_back(str);
                    str = "";
                }
            } else {
                str += s[i];
            }
        }
        if (str != ""){
            l.push_back(str);
            str = "";
        }

        // reverse
        for (auto i=l.rbegin(); i != l.rend(); i++){
            str = str + *i;
            str += ' ';
        }
        return str.substr(0, str.size()-1);
    }
};