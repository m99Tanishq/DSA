#include <iostream>
#include <string>
using namespace std;

void solve()
{
    string s = "CBAABCAB";
    stack<char> st;

    for (auto c : s)
    {
        if (c == 'B')
        {
            if (!st.empty() and st.top() == 'A')
            {
                st.pop();
            }
            else
            {
                st.push(c);
            }
        }
        else if (c == 'C')
        {
            continue;
        }
        else
        {
            st.push(c);
        }
    }
    string ans = "";
    while (!st.empty())
    {
        ans += st.top();
        st.pop();
    }
    reverse(ans.begin(), ans.end());
    cout << ans << endl;
}