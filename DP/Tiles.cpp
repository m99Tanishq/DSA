#include <bits/stdc++.h>
using namespace std;

void main(){
    int n = 5;
    int dp[n + 1];
    dp[1] = dp[2] = dp[3] = 1;
    dp[4] = 2;
    for (int i = 5; i <= n; i++)
    {
        dp[i] = dp[i - 1] + dp[i - 4];
    }
    cout << dp[n] << endl;
}