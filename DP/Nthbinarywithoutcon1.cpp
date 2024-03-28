#include <bits/stdc++.h>
using namespace std;

int count(int n, int l_d)
{
    if (n == 1)
    {
        if (l_d == 1)
        {
            return 1;
        }
        else if (l_d == 0)
        {
            return 2;
        }
    }

    if (l_d == 0)
    {
        return count(n - 1, 1) + count(n - 1, 0);
    }
    else
    {
        return count(n - 1, 0);
    }
}

void main(){
    int n = 5;
    cout << count(n, 0);
}