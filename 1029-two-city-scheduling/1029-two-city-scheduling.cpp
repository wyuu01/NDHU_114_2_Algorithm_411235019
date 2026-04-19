class Solution {
public:
    int twoCitySchedCost(vector<vector<int>>& costs) {
        vector<vector<int>> cost;
        int n = costs.size();
        for (int i = 0; i < n; i++){
            cost.push_back({costs[i][0] - costs[i][1], i});
        }
        sort(cost.begin(), cost.end());
        int totalcost = 0;
        for(int i = 0; i < n; i++){
            int index = cost[i][1];
            if(i < n/2){
                totalcost += costs[index][0];
            }
            else{
                totalcost += costs[index][1];
            }
        }
        return totalcost;

    }
};