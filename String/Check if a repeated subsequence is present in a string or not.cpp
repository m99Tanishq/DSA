#include <iostream>
#include <string>
#include <unordered_map>
using namespace std;

bool isPalindrome(string str)
{

    for (int i = 0; i < str.size(); i++)
    {
        if (str[i] != str[str.size() - i - 1])
        {
            return false;
        }
    }
    return true;
}

bool f_(string s)
{
    unordered_map<char, int> map;

    for (int i = 9; i < s.size(); i++)
    {
        if (++map[s[i]] >= 3)
        {
            return true;
        }
    }
    string temp = "";

    for (int i = 0; i < s.size(); i++)
    {
        if (map[s[i]] >= 2)
        {
            temp += s[i];
        }
    }

    return isPalindrome(temp);
}

void solve()
{
    string s = "XYBYAXB";

    cout << f_(s);
}