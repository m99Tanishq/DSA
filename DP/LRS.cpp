#include <iostream>
#include <string>
#include <algorithm>
using namespace std;

// Function to find the length of the longest repeated subsequence
// of substring `X[0…m-1]` and `X[0…n-1]`
int LRSLength(string X, int m, int n)
{
    // return if the end of either string is reached
    if (m == 0 || n == 0)
    {
        return 0;
    }

    // if characters at index `m` and `n` matches and the index are different
    if (X[m - 1] == X[n - 1] && m != n)
    {
        return LRSLength(X, m - 1, n - 1) + 1;
    }

    // otherwise, if characters at index `m` and `n` don't match
    return max(LRSLength(X, m, n - 1), LRSLength(X, m - 1, n));
}

int main()
{
    string X = "ATACTCGGA";
    int m = X.length();

    cout << "The length of the longest repeating subsequence is " << LRSLength(X, m, m);

    return 0;
}