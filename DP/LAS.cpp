#include <bits/stdc++.h>
using namespace std;

void main(){
    int A[] = {8, 9, 6, 4, 5, 7, 3, 2, 4};
    int n = sizeof(A) / sizeof(A[0]);

    int dp[n][2];
    int result = 1;
    dp[0][0] = dp[0][1] = 1;
    for (int i = 1; i < n; i++)
    {
        for (int j = 0; j < i; j++)
        {
            if (A[i] > A[j])
            {
                dp[i][0] = max(dp[i][0], dp[j][1] + 1);
            }
            if (A[i] < A[j])
            {
                dp[i][1] = max(dp[i][1], dp[j][0] + 1);
            }
        }
        if (result < max(dp[i][0], dp[i][1]))
        {
            result = max(dp[i][0], dp[i][1]);
        }
    }

    cout << result;
}