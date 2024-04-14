Fractional Knapsack
    vector<pair<double, pair<double, double>>> pw = { {60, {10, 60}},
                                             {100, {20, 100}},
                                             {120, {30, 120}} };
double n = pw.size(), W = 50;

for (double i = 0; i < n; i++)
{
    pw[i].ff = pw[i].ff / pw[i].ss.ff;
}

sort(all(pw));
double ans = 0;
for (double i = n - 1; i >= 0 and W; i--)
{
    if (W >= pw[i].second.ff)
    {
        ans += pw[i].ss.ss;
        W -= pw[i].second.ff;
    }
}

if (W)
{
    ans += (W / pw[n - 1].second.ff) * pw[n - 1].ss.ss;
}
cout << ans;