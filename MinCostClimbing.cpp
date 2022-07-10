class Solution {
public:
    int minCostClimbingStairs(vector<int>& cost) {
        int first = cost[0], second = cost[1];
        for (int i = 2; i < cost.size(); ++i) {
            int temp = second;
            second = min(first, second) + cost[i];
            first = temp;
        }
        return min(first, second);
    }
};
