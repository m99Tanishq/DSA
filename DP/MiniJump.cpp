#include <bits/stdc++.h>
using namespace std;

void main()
{
    int nums[] = {4, 2, 0, 3, 2, 0, 1, 8};
    int n = sizeof(nums) / sizeof(nums[0]);
    vector<int> dp(n, 1e9);
    dp[0] = 0;
    for (int i = 1; i < n; i++)
    {
        for (int j = 0; j < i; j++)
        {
            if (i <= (j + nums[j]))
            {
                dp[i] = min(dp[i], dp[j] + 1);
            }
        }
    }
    cout << dp[n - 1];
}