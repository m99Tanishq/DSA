Merge Sort void merge(vector<int> &v, int i, int m, int j)
{
    int l = m - i + 1;
    int r = j - m;

    vector<int> left(l, 0);
    vector<int> right(r, 0);

    for (int k = 0; k < l; k++)
    {
        left[k] = v[k + i];
    }
    for (int k = 0; k < r; k++)
    {
        right[k] = v[k + m + 1];
    }

    int p = 0, q = 0;
    int cnt = i;
    while (p < l and q < r)
    {
        if (left[p] <= right[q])
        {
            v[cnt++] = left[p++];
        }
        else
        {
            v[cnt++] = right[q++];
        }
    }

    while (p < l)
    {
        v[cnt++] = left[p++];
    }

    while (q < r)
    {
        v[cnt++] = right[q++];
    }
}

void merge_sort(vector<int> &v, int i, int j)
{
    if (i < j)
    {
        int mid = (i + j) / 2;
        merge_sort(v, i, mid);
        merge_sort(v, mid + 1, j);
        merge(v, i, mid, j);
    }
}

void solve()
{
    vector<int> v = {5, 4, 3, 2, 1};
    int n = v.size();
    merge_sort(v, 0, n - 1);
    for (int i = 0; i < n; i++)
    {
        cout << v[i] << " ";
    }
}