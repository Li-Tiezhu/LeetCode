#include <iostream>
#include <vector>
#include <algorithm>
#include <unordered_set>
#include <unordered_map>

using namespace std;

class Solution {
public:
    void reverse(string& s, int left, int right) {
        for (int i = left, j = right; i < j; i++, j--) {
            swap(s[i], s[j]);
        }
    }

    string reverseLeftWords(string s, int n) {
        reverse(s, 0, s.size() - 1);
        reverse(s, 0, s.size() - n - 1);
        reverse(s, s.size() - n, s.size() - 1);

        return s;
    }
};
