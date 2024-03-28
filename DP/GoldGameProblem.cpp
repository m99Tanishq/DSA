#include <bits/stdc++.h>
using namespace std;

int findMaxCoins(vector<int> &coins, int i, int j, vector<vector<int>> &dp)
{
    if (i == j)
    {
        return coins[i];
    }
    if (i + 1 == j)
    {
        return max(coins[i], coins[j]);
    }

    if (dp[i][j] != -1)
    {
        return dp[i][j];
    }

    int start = coins[i] + min(findMaxCoins(coins, i + 2, j, dp), findMaxCoins(coins, i + 1, j - 1, dp));
    int end = coins[j] + min(findMaxCoins(coins, i, j - 2, dp), findMaxCoins(coins, i + 1, j - 1, dp));

    return dp[i][j] = max(start, end);
}

void main()
{
    vector<int> coins = {4, 6, 2, 3};

    // total number of pots (`n` is even)
    int n = coins.size();

    // Create a table to store solutions to subproblems
    vector<vector<int>> dp(n + 1, vector<int>(n + 1, -1));

    cout << "The Maximum coins collected by player is "
         << findMaxCoins(coins, 0, n - 1, dp);
}