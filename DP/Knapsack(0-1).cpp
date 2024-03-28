#include <bits/stdc++.h>
using namespace std;

void main(){
    int v[] = {20, 5, 10, 40, 15, 25};
    int w[] = {1, 2, 3, 8, 7, 4};
    int n = sizeof(v) / sizeof(v[0]);
    // knapsack capacity
    int W = 10;

    vector<vector<int>> dp(n + 1, vector<int>(W + 1, 0));

    for (int i = 1; i <= n; i++)
    {
        for (int j = 0; j <= W; j++)
        {
            if (w[i - 1] > j)
            {
                dp[i][j] = dp[i - 1][j];
            }
            else
            {
                dp[i][j] = max(dp[i - 1][j], dp[i - 1][j - w[i - 1]] + v[i - 1]);
            }
        }
    }
    cout << dp[n][W];
}