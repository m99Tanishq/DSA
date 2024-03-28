#include <iostream>
#include <string>
#include <map>
#include <unordered_map>
#include <vector>

using namespace std;

// Top Down
// int LCS(string X, string Y, int m, int n, unordered_map<string, int> &mp)
// {
//     if(n == 0 || m == 0){
//         return 0;
//     } 
//     string key = to_string(m) + "|" + to_string(n);
//     if(mp.find(key) == mp.end()){
//         if(X[m-1] == Y[n-1]){
//             mp[key] == LCS(X,Y,m-1,n-1,mp) + 1;
//         }
//         else{
//             mp[key] = max(LCS(X,Y,m,n-1,mp), LCS(X,Y,m-1,n,mp));
//         }
//     }
//     return mp[key];
// }

// int main(){
//     string X = "ABCBDAB", Y = "BDCABA";
//     unordered_map<string, int> mp;
//     cout << "The length of the LCS is " << LCS(X, Y, X.length(), Y.length(), mp);
//     return 0;
// }

//Bottom Up
int main(){
    string X = "ABCBDAB", Y = "BDCABA";
    int n = X.length(); int m = Y.length();
    vector<vector<int>> dp(n+1, vector<int> (m+1, 0));

    for(int i = 1; i <= n; i++){
        for(int j = 1; j <= m; j++){
            if(X[i-1] == Y[j-1]){
                dp[i][j] = dp[i-1][j-1] + 1;
            }
            else{
                dp[i][j] = max(dp[i-1][j], dp[i][j-1]);
            }
        }
    }
    return 0;
}
// print lcs
string lcs(auto &dp, string X, string Y, int n, int m)
{
    if (m == 0 || n == 0)
    {
        return "";
    }

    if (X[n - 1] == Y[m - 1])
    {
        return lcs(dp, X, Y, n - 1, m - 1) + X[n - 1];
    }

    if (dp[n - 1][m] > dp[n][m - 1])
    {
        return lcs(dp, X, Y, n - 1, m);
    }
    else
    {
        return lcs(dp, X, Y, n, m - 1);
    }
}
