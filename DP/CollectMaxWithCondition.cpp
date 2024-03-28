#include <bits/stdc++.h>
using namespace std;

bool isSafe(vector<vector<int>> &v, int i, int j)
{
    return !(i < 1 || i > v.size() || j < 1 || j > v.size() || v[i - 1][j - 1] == -1);
}

int count(vector<vector<int>> &v, int n, int m)
{
    if (!isSafe(v, n, m))
    {
        return 0;
    }

    if ((n % 2) == 1)
    {
        return v[n - 1][m - 1] + max(count(v, n + 1, m), count(v, n, m + 1));
    }
    else
    {
        return v[n - 1][m - 1] + max(count(v, n + 1, m), count(v, n, m - 1));
    }
}

void main(){
    vector<vector<int>> v =
        {
            {1, 1, -1, 1, 1},
            {1, 0, 0, -1, 1},
            {1, 1, 1, 1, -1},
            {-1, -1, 1, 1, 1},
            {1, 1, -1, -1, 1}};
    int n = v.size();
    vector<vector<int>> dp(n + 1, vector<int>(n + 1, 0));
    // dp[0][0] = 1;

    for (int i = 1; i <= n; i++)
    {
        if (i & 1)
        {
            // process current row from left to right
            for (int j = 1; j <= n; j++)
            {
                if (v[i - 1][j - 1] == -1)
                {
                    dp[i][j] = 0;
                }
                else
                {
                    dp[i][j] = v[i - 1][j - 1] + max(dp[i][j - 1], dp[i - 1][j]);
                }
            }
        }
        else
        {
            // process current row from right to left
            for (int j = n; j >= 1; j--)
            {
                if (v[i - 1][j - 1] == -1)
                {
                    dp[i][j] = 0;
                }
                else
                {
                    dp[i][j] = v[i - 1][j - 1] + max(dp[i][j + 1], dp[i - 1][j]);
                }
            }
        }
    }
    cout << dp[n][n];
}