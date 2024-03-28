#include <iostream>
#include <string>
using namespace std;

// Function to find the length of the shortest common supersequence of
// sequences `X[0…m-1]` and `Y[0…n-1]`
int SCSLength(string X, string Y)
{
    int m = X.length(), n = Y.length();

    // lookup table stores solution to already computed subproblems
    // i.e., `lookup[i][j]` stores the length of SCS of substring
    // `X[0…i-1]` and `Y[0…j-1]`
    int lookup[m + 1][n + 1];

    // initialize the first column of the lookup table
    for (int i = 0; i <= m; i++)
    {
        lookup[i][0] = i;
    }

    // initialize the first row of the lookup table
    for (int j = 0; j <= n; j++)
    {
        lookup[0][j] = j;
    }

    // fill the lookup table in a bottom-up manner
    for (int i = 1; i <= m; i++)
    {
        for (int j = 1; j <= n; j++)
        {
            // if the current character of `X` and `Y` matches
            if (X[i - 1] == Y[j - 1])
            {
                lookup[i][j] = lookup[i - 1][j - 1] + 1;
            }
            // otherwise, if the current character of `X` and `Y` don't match
            else
            {
                lookup[i][j] = min(lookup[i - 1][j] + 1, lookup[i][j - 1] + 1);
            }
        }
    }

    // SCS will be the last entry in the lookup table
    return lookup[m][n];
}

int main()
{
    string X = "ABCBDAB", Y = "BDCABA";

    cout << "The length of the shortest common supersequence is "
         << SCSLength(X, Y);

    return 0;
}