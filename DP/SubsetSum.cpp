#include <bits/stdc++.h>
using namespace std;

bool subset(const std::vector<int>& v, int index, int k, unordered_map<string, bool>& mp) {
    if (k == 0)
    {
        return 1;
    }

    if (index < 0 || k < 0)
    {
        return 0;
    }
    string key = to_string(index) + "|" + to_string(k);
    if (mp.find(key) == mp.end())
    {
        mp[key] = subset(v, index - 1, k, mp) || subset(v, index - 1, k - v[index], mp);
    }
    return mp[key];
}

int main() {
    vector<int> v = {7, 3, 2, 5, 8};
    int k = 14;

    int n = v.size();
    unordered_map<string, bool> mp;
    if (subset(v, n - 1, k, mp)) {
        return 0;
    }
    std::cout << "YES" << endl;
    return 0;
}