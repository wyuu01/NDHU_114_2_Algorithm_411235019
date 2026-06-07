class Solution {
public:
    bool grouped(int curr, int group, const vector<vector<int>>& graph, vector<int>& groupAssign){
        groupAssign[curr] = group;
        for(int enemy: graph[curr]){
            if(groupAssign[enemy] != 0){
                if(groupAssign[enemy] == group){
                    return false;
                }
            }
            else{
                if(!grouped(enemy, -group, graph, groupAssign)){
                    return false;
                }
            }
        }
        return true;
    }
    bool possibleBipartition(int n, vector<vector<int>>& dislikes) {
        vector<vector<int>> graph(n+1);
        for(auto& dislike: dislikes){
            int u = dislike[0];
            int v = dislike[1];
            graph[u].push_back(v);
            graph[v].push_back(u);
        }
        vector<int> groupAssign(n+1, 0);
        for (int i = 1; i <= n; i++) {
            if (groupAssign[i] == 0) {
                if (!grouped(i, 1, graph, groupAssign)) {
                    return false;
                }
            }
        }
        return true;
    }
};