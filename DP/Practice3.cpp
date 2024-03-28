#include <bits/stdc++.h>
using namespace std;

void main()
{
    vector<int> nums = {1, 2, 9, 4, 5, 0, 4, 11, 6};
    int n = nums.size();

    vector<int> dp(n, 0);
    dp[0] = nums[0];
    dp[1] = max(nums[0], nums[1]);
    for (int i = 2; i < n; i++)
    {
        dp[i] = max(dp[i - 1], dp[i - 2] + nums[i]);
    }
    cout << dp[n - 1];
}