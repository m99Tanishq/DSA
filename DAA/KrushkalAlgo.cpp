Krushkal Algo struct Edge
{
    int src, dest, weight;
};

class Disjointset
{
    unordered_map<int, int> parent;

public:
    void makeset(int n)
    {
        for (int i = 0; i < n; i++)
        {
            parent[i] = i;
        }
    }

    int Find(int k)
    {
        if (parent[k] == k)
        {
            return k;
        }
        return Find(parent[k]);
    }

    void Union(int a, int b)
    {
        int x = Find(a);
        int y = Find(b);

        parent[x] = y;
    }
};

struct compare
{
    bool operator()(Edge &a, Edge &b)
    {
        return a.weight > b.weight;
    }
};

void Krushkal(vector<Edge> &g, int n)
{
    vector<Edge> ans;

    sort(g.begin(), g.end(), compare());
    Disjointset ds;
    ds.makeset(n);

    while (ans.size() != n - 1)
    {
        Edge x = g.back();
        g.pop_back();

        int p = ds.Find(x.src);
        int q = ds.Find(x.dest);

        if (p != q)
        {
            ans.push_back(x);
            ds.Union(p, q);
        }
    }
    for (Edge x : ans)
    {
        cout << "(" << x.src << ", " << x.dest << ", " << x.weight << ")" << endl;
    }
}

void solve()
{
    vector<Edge> g =
        {
            {0, 1, 7},
            {1, 2, 8},
            {0, 3, 5},
            {1, 3, 9},
            {1, 4, 7},
            {2, 4, 5},
            {3, 4, 15},
            {3, 5, 6},
            {4, 5, 8},
            {4, 6, 9},
            {5, 6, 11}};

    int n = 7;
    Krushkal(g, n);
}