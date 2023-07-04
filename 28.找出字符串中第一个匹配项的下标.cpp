#include <iostream>
#include <vector>
#include <algorithm>
#include <unordered_set>
#include <unordered_map>

using namespace std;

class Solution{
public:
    void getNext(int* next, const string& s) {
        int j = 0;
        next[0] = j;

        for (int i = 1; i < s.size(); i++) {
            while (j >= 0 && s[i] != s[j]) {
                j = next[j - 1];
            }

            if (s[i] == s[j]) {
                j++;
            }
            next[i] = j;
        }
    }

    int strStr(string haystack, string needle) {
        // KMP方法
        int next[needle.size()];
        getNext(next, needle);
        int j = 0;
        for (int i = 0; i < haystack.size(); i++) {
            if (haystack[i] != needle[j]) {
                j = next[j - 1];
            }
            else {
                j++;
            }
            if (j == needle.size()) {
                return (i - needle.size() + 1);
            }
        }

        return -1;

        // 暴力方法
        // int j = 0, tmp = 0;

        // for (int i = 0; i < haystack.size(); i++) {
        //     if (haystack[i] == needle[0]) {
        //         tmp = i;

        //         j = 1;
        //         i++;
        //         while (i < haystack.size() && j < needle.size() && haystack[i] == needle[j]) {
        //             i++;
        //             j++;
        //         }
        //         if (j == needle.size()) {
        //             return tmp;
        //         }
        //         else {
        //             i = tmp;
        //         }
        //     }
        // }

        // return -1;
    }
};
