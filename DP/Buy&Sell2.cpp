#include <bits/stdc++.h>
using namespace std;

int f_(int i, bool buy, vector<int> values, int n, int cap, vector<vector<vector<int>>> &dp)
{
    if (i == n || cap == 0)
    {
        return 0;
    }
    if (dp[i][buy][cap] != -1)
        return dp[i][buy][cap];
    int profit = 0;
    if (buy)
    {
        profit = max(-values[i] + f_(i + 1, 0, values, n, cap, dp), f_(i + 1, 1, values, n, cap, dp));
    }
    else
    {
        profit = max(values[i] + f_(i + 1, 1, values, n, cap - 1, dp), f_(i + 1, 0, values, n, cap, dp));
    }
    return dp[i][buy][cap] = profit;
}

void main()
{
    vector<int> values = {1, 5, 2, 3, 7, 6, 4, 5};
    int n = values.size();
    vector<vector<vector<int>>> dp(n, vector<vector<int>>(2, vector<int>(3, -1)));
    int cap = 2;
    cout << f_(0, 1, values, n, cap, dp);
}