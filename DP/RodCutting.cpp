#include <bits/stdc++.h>
using namespace std;

int f_(int n, int N, vector<int> &price)
{
    if (N == 0)
    {
        return 0;
    }

    int maxi = INT_MIN;

    for (int i = 1; i <= N; i++)
    {
        int cost = price[i - 1] + f_(n, N - i, price);
        if (cost > maxi)
        {
            maxi = cost;
        }
    }
    return maxi;
}

void main(){
    vector<int> price = {1, 5, 8, 9, 10, 17, 17, 20};
    int N = 4;
    int n = price.size();

    cout << f_(n, N, price);

    /*
    vector<int> dp(N+1, 0);
    for(int i = 1; i <= N; i++){
      for(int j = 1; j <= i; j++){
        dp[i] = max(dp[i], dp[i-j] + price[j-1]);
      }
    }
    cout << dp[N];
  */
}
