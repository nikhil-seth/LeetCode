// 871. Minimum Number of Refueling Stops

class Solution {
public:
    int minRefuelStops(int target, int startFuel, vector<vector<int>>& stations){
        int ctr=0,j=0;
        priority_queue<int> pq;
        while(startFuel<target){
            while(j<stations.size() && stations[j][0]<=startFuel)
                pq.push(stations[j++][1]);
            if(pq.empty())
                break;
            else
                startFuel+=pq.top(),pq.pop(),ctr+=1;
        }
        return startFuel<target?-1:ctr;
    }
};
