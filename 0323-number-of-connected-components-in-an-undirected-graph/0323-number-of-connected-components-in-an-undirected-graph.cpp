// solved by Milon
class Solution {
public:
    void DFS(vector<vector<int>>& graph, vector<bool>& visited, int s){
        
        visited[s] = true;
        for(int u: graph[s]){
            if(!visited[u])
                DFS(graph, visited, u);
        }
    }
    int countComponents(int n, vector<vector<int>>& edges) {
        vector<bool> visited(n, false);
        
        vector<vector<int>> graph(n, vector<int>());
        for(vector<int> edg: edges){
            graph[edg[1]].push_back(edg[0]);
            graph[edg[0]].push_back(edg[1]);
        }
        
        int res = 0;
        for(int i = 0; i < n; i++){
            
            if(!visited[i]){
                res++;
                
                DFS(graph, visited, i);
            }
        }
        return res;
    }
};