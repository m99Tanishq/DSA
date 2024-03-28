#include <bits/stdc++.h>
using namespace std;

const int M = 100;

int findMinAdjustmentCost(int A[], int n, int target)
{
    if (n == 0)
    {
        return 0;
    }
    int dp[n][M + 1];

    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j <= M; j++)
        {
            if (i == 0)
            {
                dp[i][j] = abs(j - A[i]);
            }
            else
            {
                dp[i][j] = INT_MAX;
                int k = max(0LL, j - target);
                while (k <= min(M, j + target))
                {
                    dp[i][j] = min(dp[i][j], dp[i - 1][k] + abs(j - A[i]));
                    k++;
                }
            }
        }
    }
    int result = INT_MAX;
    for (int i = 0; i <= M; i++)
    {
        result = min(result, dp[n - 1][i]);
    }
    return result;
}

void main()
{
    int A[] = {55, 77, 52, 61, 39, 6, 25, 60, 49, 47};
    int target = 10;

    int n = sizeof(A) / sizeof(A[0]);
    cout << findMinAdjustmentCost(A, n, target);
}