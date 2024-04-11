#include <iostream>
#include <string>
#include <vector>
using namespace std;

void solve()
{
    string s = "ABCCBA";
    int n = s.size();

    vector<int> v(26, 0);
    for (int i = 0; i < n; i++)
    {
        v[s[i] - 'A']++;
    }
    int odd = 0;
    for (int i = 0; i < 26; i++)
    {
        if ((v[i] & 1))
            odd++;
    }

    if ((n & 1) and odd == 1)
        cout << "true\n";
    else if (!(n & 1) and !odd)
        cout << "true\n";
    else
        cout << "false\n";
}
