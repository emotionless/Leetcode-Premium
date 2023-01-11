// solved by Milon

class Solution {
public:
    
    void dfs(int u, const vector<vector<int>> &adj, vector<bool> &vis) {
        if (vis[u]) return; 
        vis[u] = true;
        for (auto v : adj[u]) {
            dfs(v, adj, vis);
        }
    }
    
    bool validTree(int n, vector<vector<int>>& edges) {
        if ((n-1) != edges.size()) return false;
        vector<vector<int>> adj(n);
        for (auto ele : edges) {
            adj[ele[0]].push_back(ele[1]);
            adj[ele[1]].push_back(ele[0]);
        }
        vector<bool> vis(n, false);
        dfs(0, adj, vis);
        for (int i = 0; i < n; i++) {
            if (vis[i] == false) {
                return false;
            }
        }
        return true;
    }
};