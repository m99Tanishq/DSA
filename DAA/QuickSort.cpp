Quick Sort int partition(vector<int> &v, int i, int j)
{
    int pivot = v[j];
    int l = i - 1;

    for (int k = i; k < j; k++)
    {
        if (v[k] < pivot)
        {
            l++;
            swap(v[l], v[k]);
        }
    }
    swap(v[l + 1], v[j]);
    return l + 1;
}

void quick_sort(vector<int> &v, int i, int j)
{
    if (i < j)
    {
        int p = partition(v, i, j);
        quick_sort(v, i, p - 1);
        quick_sort(v, p + 1, j);
    }
}

void solve()
{
    vector<int> v = {5, 4, 3, 2, 1};
    int n = v.size();
    quick_sort(v, 0, n - 1);
    for (int i = 0; i < n; i++)
    {
        cout << v[i] << " ";
    }
}