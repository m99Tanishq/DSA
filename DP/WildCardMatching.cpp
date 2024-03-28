#include <bits/stdc++.h>
using namespace std;

bool f_(string Y, int m, string X, int n, vector<vector<bool>> &dp)
{
    if (n < 0 and m < 0)
        return 1;

    if (n < 0 and m >= 0)
    {
        return 0;
    }
    if (m < 0)
    {
        for (int i = 0; i <= n; i++)
        {
            if (X[i] != '*')
            {
                return 0;
            }
        }
        return 1;
    }

    if (dp[n][m] == -1)
    {
        if (X[n] == '*')
        {
            dp[n][m] = f_(Y, m - 1, X, n, dp) || f_(Y, m, X, n - 1, dp);
        }
        else
        {
            if (X[n] != '?' and X[n] != Y[m])
            {
                dp[n][m] = 0;
            }
            else
            {
                dp[n][m] = f_(Y, m - 1, X, n - 1, dp);
            }
        }
    }
    return dp[n][m];
}

void main()
{
    string word = "xyxzzxy";
    string pattern = "x***x?";
    int m = word.size();
    int n = pattern.size();

    vector<vector<bool>> dp(n + 1, vector<bool>(m + 1, -1));

    cout << f_(word, n - 1, pattern, m - 1, dp);
}