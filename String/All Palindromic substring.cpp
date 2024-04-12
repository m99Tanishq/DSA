#include <iostream>
#include <string>
#include <unordered_set>
using namespace std;



void f_1(string str, int l, int h, unordered_set<string> &set)
{

    while (l >= 0 and h < str.length() and str[l] == str[h])
    {
        set.insert(str.substr(l, h - l + 1));
        l--, h++;
    }
}

void f_(string str)
{

    unordered_set<string> set;
    int n = str.length();
    for (int i = 0; i < n; i++)
    {
        f_1(str, i, i, set);
        f_1(str, i, i + 1, set);
    }

    for (auto x : set)
    {
        cout << x << " ";
    }
}

void solve()
{
    string str = "aaa";
    f_(str);
}