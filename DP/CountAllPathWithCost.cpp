#include <bits/stdc++.h>
using namespace std;

int path(int n, int m, vector<vector<int>> &mat, int cost, unordered_map<string, int> &mp)
{
    if (cost < 0)
    {
        return 0;
    }
    if (m == 0 && n == 0)
    {
        if (mat[0][0] - cost == 0)
        {
            return 1;
        }
        else
        {
            return 0;
        }
    }

    string key = to_string(m) + "|" + to_string(n) + "|" + to_string(cost);
    if (mp.find(key) == mp.end())
    {
        if (m == 0)
        {
            mp[key] = path(n - 1, 0, mat, cost - mat[n][m], mp);
        }
        else if (n == 0)
        {
            mp[key] = path(0, m - 1, mat, cost - mat[n][m], mp);
        }
        else
        {
            mp[key] = path(n - 1, m, mat, cost - mat[n][m], mp) + path(n, m - 1, mat, cost - mat[n][m], mp);
            ;
        }
    }
    return mp[key];
}
void main(){
    vector<vector<int>> mat =
        {
            {4, 7, 1, 6},
            {5, 7, 3, 9},
            {3, 2, 1, 2},
            {7, 1, 6, 3}};
    int n = mat.size();
    unordered_map<string, int> mp;
    int cost = 25;
    cout << path(n - 1, n - 1, mat, cost, mp);
}