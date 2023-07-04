#include <iostream>
#include <vector>
#include <algorithm>
#include <unordered_set>
#include <unordered_map>

using namespace std;

class Solution {
public:
    string replaceSpace(string s) {
        int count = 0;
        int sOldSize = s.size();
        for (int i = 0; i < s.size(); i++) {
            if (s[i] == ' ') {
                count++;
            }
        }

        s.resize(sOldSize + count * 2);
        int sNewSize = s.size();

        for (int i = sNewSize - 1, j = sOldSize - 1; j < i; j--, i--) {
            if (s[j] != ' ') {
                s[i] = s[j];
            }
            else {
                s[i] = '0';
                s[--i] = '2';
                s[--i] = '%';
            }
        }

        return s;
    }
};
