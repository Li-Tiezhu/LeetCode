#include <algorithm>
#include <iostream>
#include <vector>

using namespace std;

class Solution {
   public:
    int climbStairs(int n) {
        vector<int> dp(n + 1, 0);
        dp[0] = 1;
        for (int j = 1; j <= n; j++) {
            for (int i = 1; i <= 2; i++) {
                if (j >= i) {
                    dp[j] += dp[j - i];
                }
            }
        }
        return dp[n];
    }
};

int main() {
    Solution s;
    vector<int> coins({1, 2, 3});
    int ret = s.climbStairs(3);
    cout << ret << endl;
};
