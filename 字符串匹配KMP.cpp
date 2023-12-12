// https://leetcode.cn/leetbook/read/array-and-string/cm5e2/
#include <string>
using namespace std;

// 暴力方法
class Solution {
public:
    int strStr(string haystack, string needle) {
        if (needle.size() > haystack.size()){
            return -1;
        }
        int match = 0;
        for (int i=0; i<haystack.size() - needle.size() + 1; i++){
            match = 0;
            for (int j=0; j< needle.size(); j++){
                if (needle[j] != haystack[i+j]){
                    break;
                } else {
                    match ++;
                }
            }
            if (match == needle.size()){
                return i;
            }
        }
        return -1;
    }
};


// KMP