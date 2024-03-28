#include <bits/stdc++.h>
using namespace std;

int mcm(int i, int j, const vector<int> &dims)
{
    if (i == j)
        return 0;

    int mini = INT_MAX;

    for (int k = i; k < j; k++)
    {
        int temp = mcm(i, k, dims) + mcm(k + 1, j, dims) + (dims[i - 1] * dims[k] * dims[j]);
        mini = min(mini, temp);
    }

    return mini;
}

void main(){
    vector<int> dims = {10, 30, 5, 60};
    int mini = 1e9;
    cout << mcm(1, dims.size() - 1, dims);
}