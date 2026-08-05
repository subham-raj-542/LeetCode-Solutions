class Solution {
public:
    vector<int> remainingMethods(int n, int k, vector<vector<int>>& invocations) {
        vector<vector<int>> g(n);
        vector<bool> suspicious(n, false);

        for (auto &e : invocations) {
            g[e[0]].push_back(e[1]);
        }

        // Find all suspicious methods reachable from k
        function<void(int)> dfs = [&](int u) {
            suspicious[u] = true;
            for (int v : g[u]) {
                if (!suspicious[v]) {
                    dfs(v);
                }
            }
        };

        dfs(k);

        // If any non-suspicious method calls a suspicious one,
        // we cannot remove anything.
        for (auto &e : invocations) {
            int u = e[0], v = e[1];
            if (!suspicious[u] && suspicious[v]) {
                vector<int> ans(n);
                iota(ans.begin(), ans.end(), 0);
                return ans;
            }
        }

        // Remove all suspicious methods
        vector<int> ans;
        for (int i = 0; i < n; i++) {
            if (!suspicious[i]) {
                ans.push_back(i);
            }
        }

        return ans;
    }
};