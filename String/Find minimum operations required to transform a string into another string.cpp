#include <iostream>
#include <string>
using namespace std;

void solve()
{
    string first = "ADCB";
    string second = "ABCD";

    int count = 0;
    for (int i = first.length() - 1, j = i; i >= 0; i--, j--)
    {
        while (first[i] != second[j] and i >= 0)
        {
            i--;
            count++;
        }
    }

    cout << count << endl;
}