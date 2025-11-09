bool hasCircularDependency(int n, vector<vector<int>> dependencies) {
vector<vector<int>> adj(n);
    vector<int> indegree(n, 0);

    // Build graph and indegree
    for (auto& dep : dependencies) {
        int u = dep[0];
        int v = dep[1];
        adj[v].push_back(u);  
        indegree[u]++;
    }

    queue<int> q;
    for (int i = 0; i < n; i++) {
        if (indegree[i] == 0)
            q.push(i);
    }

    int count = 0;

    while (!q.empty()) {
        int u = q.front();
        q.pop();
        count++;

        for (int v : adj[u]) {
            indegree[v]--;
            if (indegree[v] == 0)
                q.push(v);
        }
    }

    return (count == n) ? 0 : 1;
}