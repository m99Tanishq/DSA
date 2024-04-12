#include <iostream>
#include <string>
#include <unordered_map>
#include <unordered_set>
using namespace std;

void solve()
{
    string x = "ACAB";
    string y = "XCXY";

    unordered_map<char, char> map;
    unordered_set<char> set;

    for (int i = 0; i < x.length(); i++)
    {
        if (map.find(x[i]) != map.end())
        {
            if (map[x[i]] != y[i])
            {
                cout << "NO\n";
                return;
            }
        }
        else
        {

            if (set.find(y[i]) != set.end())
            {
                cout << "NO\n";
                return;
            }
            map[x[i]] = y[i];
            set.insert(y[i]);
        }
    }
    cout << "YES\n";
}