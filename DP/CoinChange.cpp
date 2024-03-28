#include <bits/stdc++.h>
using namespace std;

int f_(vector<int> &S, int target)
{
    if (target == 0)
    {
        return 1;
    }
    if (target < 0)
    {
        return 0;
    }
    int coins = 0;
    for (int i = 0; i < S.size(); i++)
    {
        coins += f_(S, target - S[i]);
    }
    return coins;
}

void main(){
    vector<int> S = {1, 2, 3};
    int N = 4;
    // cout << f_(S,N);
    vector<int> dp(N + 1, 0);

    dp[0] = 1;

    for (int i = 1; i <= N; i++)
    {
        for (int j = 0; j < S.size() and i >= S[j]; j++)
        {
            dp[i] += dp[i - S[j]];
        }
    }
    cout << dp[N];
}