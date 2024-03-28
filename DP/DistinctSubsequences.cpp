#include <bits/stdc++.h>
using namespace std;

int count(string X, string Y, int n, int m)
{
    if (n == 1 and m == 1)
    {
        return (X[0] == Y[0]);
    }
    if (m == 0)
    {
        return 1;
    }
    if (n == 0)
    {
        return 0;
    }

    if (m > n)
    {
        return 0;
    }

    return ((X[n - 1] == Y[m - 1]) ? count(X, Y, n - 1, m - 1) : 0) +
           count(X, Y, n - 1, m);
}

void main(){
    string X = "subsequence"; // input string
    string Y = "sue";         // pattern

    // cout << count(X, Y, X.size(), Y.size());
    int n = X.size();
    int m = Y.size();
    vector<vector<int>> dp(n + 1, vector<int>(m + 1, 0));

    for (int i = 0; i <= n; i++)
    {
        dp[i][0] = 1;
    }

    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= m; j++)
        {
            if (X[i - 1] == Y[j - 1])
            {
                dp[i][j] = dp[i - 1][j - 1] + dp[i - 1][j];
            }
            else
            {
                dp[i][j] = dp[i - 1][j];
            }
        }
    }
    cout << dp[n][m];
}