
class Solution {
public:
    using ll = long long;

    int n, timer;
    vector<vector<int>> adj;
    vector<int> parent, depth, heavy, head, pos, sz;
    vector<int> seg;

    int dfs(int u, int p) {
        parent[u] = p;
        sz[u] = 1;
        int maxSub = 0;

        for (int v : adj[u]) {
            if (v == p) continue;

            depth[v] = depth[u] + 1;
            int sub = dfs(v, u);
            sz[u] += sub;

            if (sub > maxSub) {
                maxSub = sub;
                heavy[u] = v;
            }
        }
        return sz[u];
    }

    void decompose(int u, int h) {
        head[u] = h;
        pos[u] = timer++;

        if (heavy[u] != -1)
            decompose(heavy[u], h);

        for (int v : adj[u]) {
            if (v == parent[u] || v == heavy[u]) continue;
            decompose(v, v);
        }
    }

    void build(int node, int l, int r, string& s) {
        if (l == r) {
            seg[node] = 1 << (s[l] - 'a');
            return;
        }

        int mid = (l + r) / 2;
        build(node * 2, l, mid, s);
        build(node * 2 + 1, mid + 1, r, s);
        seg[node] = seg[node * 2] ^ seg[node * 2 + 1];
    }

    void update(int node, int l, int r, int idx, int val) {
        if (l == r) {
            seg[node] = val;
            return;
        }

        int mid = (l + r) / 2;

        if (idx <= mid)
            update(node * 2, l, mid, idx, val);
        else
            update(node * 2 + 1, mid + 1, r, idx, val);

        seg[node] = seg[node * 2] ^ seg[node * 2 + 1];
    }

    int query(int node, int l, int r, int ql, int qr) {
        if (ql > r || qr < l) return 0;

        if (ql <= l && r <= qr) return seg[node];

        int mid = (l + r) / 2;

        return query(node * 2, l, mid, ql, qr) ^
               query(node * 2 + 1, mid + 1, r, ql, qr);
    }

    int pathQuery(int u, int v) {
        int mask = 0;

        while (head[u] != head[v]) {
            if (depth[head[u]] < depth[head[v]])
                swap(u, v);

            mask ^= query(1, 0, n - 1, pos[head[u]], pos[u]);
            u = parent[head[u]];
        }

        if (depth[u] > depth[v]) swap(u, v);

        mask ^= query(1, 0, n - 1, pos[u], pos[v]);

        return mask;
    }

    vector<bool> palindromePath(int n,
                                vector<vector<int>>& edges,
                                string s,
                                vector<string>& queries) {
        this->n = n;
        timer = 0;

        adj.assign(n, {});
        parent.resize(n);
        depth.assign(n, 0);
        heavy.assign(n, -1);
        head.resize(n);
        pos.resize(n);
        sz.resize(n);

        for (auto& e : edges) {
            adj[e[0]].push_back(e[1]);
            adj[e[1]].push_back(e[0]);
        }

        dfs(0, -1);
        decompose(0, 0);

        string ordered(n, 'a');
        for (int u = 0; u < n; u++)
            ordered[pos[u]] = s[u];

        seg.assign(4 * n, 0);
        build(1, 0, n - 1, ordered);

        vector<bool> ans;

        for (string& q : queries) {
            string type;
            int u;
            string third;

            stringstream ss(q);
            ss >> type >> u >> third;

            if (type == "update") {
                char c = third[0];
                s[u] = c;
                update(1, 0, n - 1, pos[u], 1 << (c - 'a'));
            } else {
                int v = stoi(third);
                int mask = pathQuery(u, v);

                ans.push_back((mask & (mask - 1)) == 0);
            }
        }

        return ans;
    }
};
