// solved by Milon

class Solution {
public:
    
    struct Node {
        int node, rem, cst;
        Node(int node, int rem, int cst) {
            this->node = node;
            this->rem = rem;
            this->cst = cst;
        }
    };
    
    struct Comparator {
        bool operator()(const Node &a, const Node &b) {
            return -a.cst < -b.cst;
        }
    };
    
    int minimumCost(int n, vector<vector<int>>& highways, int discounts) {
        vector<vector<pair<int, int>>> adj;
        adj.resize(n);
        for (auto highway : highways) {
            adj[highway[0]].push_back({highway[1], highway[2]});
            adj[highway[1]].push_back({highway[0], highway[2]});
        }
        priority_queue<Node, vector<Node>, Comparator> pq;
        pq.push(Node(0, discounts, 0));
        vector<vector<int>> cost(n, vector<int>(discounts + 1, INT_MAX));
        cost[0][discounts] = 0;
        
        while (!pq.empty()) {
            Node cur = pq.top();
            pq.pop();
            int node = cur.node;
            int rem = cur.rem;
            int cst = cur.cst;
            
            if (node == (n-1)) {
                return cst;
            }
            for (auto v : adj[node]) {
                int adjn = v.first;
                int adjc = v.second;
                if ((cst + adjc) < cost[adjn][rem]) {
                    cost[adjn][rem] = cst + adjc;
                    pq.push(Node(adjn, rem, cst + adjc));
                }
                if (rem > 0 && (cst + adjc/2) < cost[adjn][rem-1]) {
                    cost[adjn][rem-1] = cst + adjc/2;
                    pq.push(Node(adjn, rem - 1, cst + adjc/2));
                }
            }
        }
        return -1;
    }
};