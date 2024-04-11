#include <iostream>
#include <string>
#include <vector>
using namespace std;

string s1 = "abracadabra";
int n = s1.size();
string s2 = s1;
reverse(s2.begin(), s2.end());
string temp = "";
vector<vector<int>> dp(n + 1, vector<int>(n + 1, 0));
int maxi = 0;
for (int i = 1; i <= n; i++)
{
    for (int j = 1; j <= n; j++)
    {
        if (s1[i - 1] == s2[j - 1])
        {
            dp[i][j] = dp[i - 1][j - 1] + 1;
        }
        else
        {
            dp[i][j] = 0;
        }
        if (maxi < dp[i][j])
        {
            temp = s1.substr(i - dp[i][j], dp[i][j]);
            maxi = dp[i][j];
        }
    }
}
cout << temp << endl;