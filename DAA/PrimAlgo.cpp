vector<pair<int, int>> Prim(int V, int E, vector<vector<int>> g)
{
    vector<vector<int>> adj[V];

    for (int i = 0; i < E; i++)
    {
        int u = g[i][0];
        int v = g[i][1];
        int w = g[i][2];

        adj[u].push_back({v, w});
        adj[v].push_back({u, w});
    }

    priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;

    vector<bool> vis(V, false);
    vector<pair<int, int>> MST;
    pq.push({0, 0});

    while (!pq.empty())
    {
        auto edge = pq.top();
        pq.pop();

        int w = edge.first;
        int u = edge.second;

        if (vis[u])
        {
            continue;
        }
        vis[u] = 1;

        for (auto ngb : adj[u])
        {
            if (!vis[ngb[0]])
            {
                pq.push({ngb[1], ngb[0]}); // weight and neighbour
                MST.push_back({ngb[0], u});
            }
        }
    }
    return MST;
}

void solve()
{
    vector<vector<int>> g = {{0, 1, 7},
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

    vector<pair<int, int>> MST = Prim(7, 11, g);
    for (auto edge : MST)
    {
        cout << edge.first << " - " << edge.second << endl;
    }
}