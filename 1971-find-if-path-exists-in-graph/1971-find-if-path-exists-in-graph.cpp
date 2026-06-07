class Solution {
public:
    bool dfs(int curr, int destination, vector<vector<int>>& graph, vector<bool>& visited) {
        if (curr == destination) {
            return true;
        }

        visited[curr] = true;

        for (int neighbor : graph[curr]) {
            if (!visited[neighbor] && dfs(neighbor, destination, graph, visited)) {
                return true;
            }
        }

        return false;
    }
    bool validPath(int n, vector<vector<int>>& edges, int source, int destination) {
        vector<vector<int>> graph(n);
        for (const auto& edge: edges){
            int u = edge[0];
            int v = edge[1];
            graph[u].push_back(v);
            graph[v].push_back(u);
        }
        vector<bool> visited(n, false);
        return dfs(source, destination, graph, visited);
    }
};