//746. Min Cost Climbing Stairs
class Solution {
public:
    int minCostClimbingStairs(vector<int>& cost) {
        int n=cost.size();
        if(n==0)
            return 0;
        if(n==1)
            return cost[0];
        for(int i=2;i<n;i++)
            cost[i]+=min(cost[i-2],cost[i-1]);
        return min(cost[n-1],cost[n-2]);
    }
};
