#include <bits/stdc++.h>
using namespace std;
int f_(int i, bool buy, vector<int> values, int n, vector<int> &dp)
{
    if (i == n)
    {
        return 0;
    }
    int profit = 0;
    if (buy)
    {
        profit = max(-values[i] + f_(i + 1, 0, values, n, dp), f_(i + 1, 1, values, n, dp));
    }
    else
    {
        profit = max(values[i] + f_(i + 1, 1, values, n, dp), f_(i + 1, 0, values, n, dp));
    }
    return profit;
}

void main()
{
    vector<int> values = {1, 5, 2, 3, 7, 6, 4, 5};
    int n = values.size();
    vector<int> dp(n, 0);
    cout << f_(0, 1, values, n, dp);
}