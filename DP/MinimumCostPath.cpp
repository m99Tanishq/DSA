#include <bits/stdc++.h>
using namespace std;


void main(){
    vector<vector<int>> cost =
        {
            {4, 7, 8, 6, 4},
            {6, 7, 3, 9, 2},
            {3, 8, 1, 2, 4},
            {7, 1, 7, 3, 7},
            {2, 9, 8, 9, 3}};
    int n = cost.size(), m = cost[0].size();
    vector<vector<int>> dp(n + 1, vector<int>(m + 1, INT_MAX));
    dp[1][1] = cost[0][0];
    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= m; j++)
        {
            if (i == 1 and j == 1)
                continue;
            dp[i][j] = min({dp[i - 1][j], dp[i][j - 1]}) + cost[i - 1][j - 1];
        }
    }
    cout << dp[n][m];
}