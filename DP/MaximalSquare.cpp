#include <bits/stdc++.h>
using namespace std;

void main(){
    vector<vector<int>> mat =
        {
            {0, 0, 1, 0, 1, 1},
            {0, 1, 1, 1, 0, 0},
            {0, 0, 1, 1, 1, 1},
            {1, 1, 0, 1, 1, 1},
            {1, 1, 1, 1, 1, 1},
            {1, 1, 0, 1, 1, 1},
            {1, 0, 1, 1, 1, 1},
            {1, 1, 1, 0, 1, 1}};
    int n = mat.size(), m = mat[0].size();
    vector<vector<int>> dp(n + 1, vector<int>(m + 1, 1));
    int maxi = -1;
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            if (i and j and mat[i][j])
            {
                dp[i][j] = 1 + min({dp[i - 1][j], dp[i - 1][j - 1], dp[i][j - 1]});
            }
            maxi = max(maxi, dp[i][j]);
        }
    }
    cout << maxi << endl;
}