#include <bits/stdc++.h>
using namespace std;

int main(){
    vector<int> arr = {8, 4, 12, 2, 10, 6, 14, 1, 9, 5, 13, 3, 11};
    int n = arr.size();
    vector<int> dp = arr;
    int maxi = INT_MIN;
    for (int i = 0; i < n; i++)
    {
        for (int prev = 0; prev < i; prev++)
        {
            if (arr[i] > arr[prev])
            {
                dp[i] = max(dp[prev] + arr[i], dp[i]);
            }
        }
        maxi = max(dp[i], maxi);
    }
    return 0;
}