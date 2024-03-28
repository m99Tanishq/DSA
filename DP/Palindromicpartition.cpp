#include <bits/stdc++.h>
using namespace std;

bool isPalindrome(string X, int i, int j)
{
    while (i <= j)
    {
        if (X[i++] != X[j--])
        {
            return false;
        }
    }
    return true;
}

int findMinimumCuts(string X, int i, int j)
{
    if (i >= j || isPalindrome(X, i, j))
    {
        return 0;
    }

    int min = INT_MAX;

    for (int k = i; k <= j - 1; k++)
    {
        int count = 1 + findMinimumCuts(X, i, k) + findMinimumCuts(X, k + 1, j);
        if (min > count)
        {
            min = count;
        }
    }
    return min;
}

void main()
{

    string X = "BABABCBADCD"; // BAB|ABCBA|DCD

    cout << "The minimum cuts required are " << findMinimumCuts(X, 0, X.size() - 1);
}