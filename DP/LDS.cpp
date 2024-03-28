#include <bits/stdc++.h>
using namespace std;


void main(){
    vector<int> arr = {0, 8, 4, 12, 2, 10, 6, 14, 1, 9, 5, 13, 3, 11, 7, 15};
    int n = arr.size();
    // vector<vector<int>> dp(n+1, vector<int> (m+1, 1));
    vector<int> dp(n, 1);
    int maxi = 1;
    for (int i = n - 1; i >= 0; i--)
    {
        for (int prev = n - 1; prev > i; prev--)
        {
            if (arr[i] > arr[prev])
            {
                dp[i] = max(dp[prev] + 1, dp[i]);
                maxi = max(dp[i], maxi);
            }
        }
    }
    cout << maxi << endl;
}