0 / 1 Knapsack
        vector<int>
            p = {1, 2, 3};
vector<int> w = {4, 5, 6};
int W = 3, n = 3;
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
            dp[i][j] = max(dp[i - 1][j], dp[i - 1][j - w[i - 1]] + p[i - 1]);
        }
    }
}
cout << dp[n][W];