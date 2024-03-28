#include <bits/stdc++.h>
using namespace std;

int f_(vector<int> &S, int target)
{
    if (target == 0)
    {
        return 0;
    }
    if (target < 0)
    {
        return INT_MAX;
    }
    int coins = INT_MAX;
    for (int i = 0; i < S.size(); i++)
    {
        int c = f_(S, target - S[i]);

        if (c != INT_MAX)
        {
            coins = min(coins, c + 1);
        }
    }
    return coins;
}

void main(){
    vector<int> S = {1, 2, 3, 4};
    int N = 15;

    // cout << f_(S,target);

    vector<int> dp(N + 1, INT_MAX);

    dp[0] = 0;

    for (int i = 1; i <= N; i++)
    {
        for (int j = 0; j < S.size() and i >= S[j]; j++)
        {
            dp[i] = min(dp[i], 1 + dp[i - S[j]]);
        }
    }
    cout << dp[N];
}