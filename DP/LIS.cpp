#include <bits/stdc++.h>
using namespace std;

int main(){
    vector<int> arr = {0, 8, 4, 12, 2, 10, 6, 14, 1, 9, 5, 13, 3, 11, 7, 15};
    int n = arr.size();
    // vector<vector<int>> dp(n+1, vector<int> (m+1, 1));
    vector<int> dp(n, 1);
    int maxi = 1;
    for (int i = 0; i < n; i++)
    {
        for (int prev = 0; prev < n; prev++)
        {
            if (arr[i] > arr[prev])
            {
                dp[i] = max(dp[prev] + 1, dp[i]);
            }
        }
        maxi = max(dp[i], maxi);
    }
    cout << maxi << endl;
    return 0;
}

// Print LIS
// vector<int> lis;
// for (int i = n - 1; i >= 0; --i)
// {
//     if (dp[i] == maxi)
//     {
//         lis.emplace_back(v[i]);
//         maxi--;
//     }
// }
// reverse(begin(lis), end(lis));
// for (auto &it : lis)
//     cout << it << " ";
// cout << "\n";
// return res;