#include <iostream>
#include <string>
#include <algorithm>
using namespace std;

// Function to find LCS of string `X[0…m-1]` and `Y[0…n-1]`
string findLongestPalindrome(string X, string Y, int m, int n, auto &lookup)
{
    // return an empty string if the end of either sequence is reached
    if (m == 0 || n == 0)
    {
        return string("");
    }

    // If the last character of `X` and `Y` matches
    if (X[m - 1] == Y[n - 1])
    {
        // append current character (`X[m-1]` or `Y[n-1]`) to LCS of
        // substring `X[0…m-2]` and `Y[0…n-2]`
        return findLongestPalindrome(X, Y, m - 1, n - 1, lookup) + X[m - 1];
    }

    // otherwise, if the last character of `X` and `Y` are different

    // if a top cell of the current cell has more value than the left
    // cell, then drop the current character of string `X` and find LCS
    // of substring `X[0…m-2]`, `Y[0…n-1]`

    if (lookup[m - 1][n] > lookup[m][n - 1])
    {
        return findLongestPalindrome(X, Y, m - 1, n, lookup);
    }

    // if a left cell of the current cell has more value than the top
    // cell, then drop the current character of string `Y` and find LCS
    // of substring `X[0…m-1]`, `Y[0…n-2]`

    return findLongestPalindrome(X, Y, m, n - 1, lookup);
}

// Function to find the length of LCS of substring `X[0…n-1]` and `Y[0…n-1]`
int LCSLength(string X, string Y, int n, auto &lookup)
{
    // first row and first column of the lookup table are already 0

    // fill the lookup table in a bottom-up manner
    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= n; j++)
        {
            // if current character of `X` and `Y` matches
            if (X[i - 1] == Y[j - 1])
            {
                lookup[i][j] = lookup[i - 1][j - 1] + 1;
            }
            // otherwise, if the current character of `X` and `Y` don't match
            else
            {
                lookup[i][j] = max(lookup[i - 1][j], lookup[i][j - 1]);
            }
        }
    }

    return lookup[n][n];
}

int main()
{
    string X = "ABBDCACB";

    int m = X.length();

    // lookup[i][j] stores the length of LCS of substring `X[0…i-1]` and `Y[0…j-1]`
    vector<vector<int>> lookup(m + 1, vector<int>(m + 1));

    // string `Y` is a reverse of `X`
    string Y = X;
    reverse(Y.begin(), Y.end());

    // find the length of the LPS using LCS
    cout << "The length of the longest palindromic subsequence is "
         << LCSLength(X, Y, m, lookup) << endl;

    // print the LPS using a lookup table
    cout << "The longest palindromic subsequence is "
         << findLongestPalindrome(X, Y, m, m, lookup);

    return 0;
}