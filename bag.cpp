#include <algorithm>
#include <iostream>
#include <vector>

using namespace std;

class Solution {
   public:
    int bag(vector<int> weight, vector<int> value, int bagWeight) {
        vector<vector<int>> dp(weight.size(), vector<int>(bagWeight + 1, 0));
        for (int i = weight[0]; i <= bagWeight; i++) {
            dp[0][i] = value[0];
        }
        // 列优先
        for (int j = 1; j <= bagWeight; j++) {
            for (int i = 1; i < weight.size(); i++) {
                if (weight[i] > j) {
                    dp[i][j] = dp[i - 1][j];
                } else {
                    dp[i][j] =
                        max(dp[i - 1][j], dp[i - 1][j - weight[i]] + value[i]);
                }
            }
        }
        return dp[weight.size() - 1][bagWeight];
    }

    int bag_one(vector<int> weight, vector<int> value, int bagWeight) {
        vector<int> dp(bagWeight + 1, 0);
        for (int i = 0; i < weight.size(); i++) {
            for (int j = bagWeight; j >= weight[i]; j--) {
                dp[j] = max(dp[j], dp[j - weight[i]] + value[i]);
            }
        }
        return dp[bagWeight];
    }
};

int main() {
    Solution s;
    vector<int> weight({1, 3, 4});
    vector<int> value({15, 20, 30});
    int ret = s.bag_one(weight, value, 4);
    cout << ret << endl;
};
