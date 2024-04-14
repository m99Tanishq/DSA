int MCM(vector<int> &v, int i, int j, vector<vector<int>> &dp)
{
    if (i == j)
        return 0;

    if (dp[i][j] != -1)
    {
        return dp[i][j];
    }
    int step = 0;
    int mini = 1e9;

    for (int k = i; k < j; k++)
    {
        step = MCM(v, i, k, dp) + MCM(v, k + 1, j, dp) + (v[i - 1] * v[k] * v[j]);
        mini = min(mini, step);
    }
    return dp[i][j] = mini;
}

void solve()
{
    vector<int> v = {40, 20, 30, 10, 30};
    int n = 5;
    vector<vector<int>> dp(n, vector<int>(n, -1));
    cout << MCM(v, 1, n - 1, dp);
}