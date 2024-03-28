#include <bits/stdc++.h>
using namespace std;

// Ways to reach the bottom-right corner of a matrix with exactly `k` turns allowed
// https://www.techiedelight.com/reach-bottom-right-corner-matrix-exactly-k-turns/
bool isValid(int i, int j, int M, int N)
{
    return (i >= 0 && i < M && j >= 0 && j < N);
}

int totalWays(int n, int m, int i, int j, int k, bool isCol)
{

    if (k == -1 || !isValid(i, j, n, m))
    {
        return 0;
    }
    if (k == 0 and i == n - 1 and j == m - 1)
    {
        return 1;
    }

    if (isCol)
    {
        return totalWays(n, m, i + 1, j, k, isCol) + totalWays(n, m, i, j + 1, k - 1, !isCol);
    }
    return totalWays(n, m, i + 1, j, k - 1, !isCol) + totalWays(n, m, i, j + 1, k, isCol);
}

void main()
{
    int M = 3, N = 3;

    // Number of turns
    int k = 2;
    int i = 0, j = 0;
    cout << totalWays(N, M, i + 1, j, k, true) + totalWays(N, M, i, j + 1, k, false);
}