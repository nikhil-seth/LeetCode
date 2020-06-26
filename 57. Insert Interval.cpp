// 57. Insert Interval

class Solution {
public:
    vector<vector<int>> insert(vector<vector<int>>& intervals, vector<int>& newInterval){
        ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
        if(intervals.size()==0){
            intervals.push_back(newInterval);
            return intervals;
        }
        int i=0;
        while(i<intervals.size() && intervals[i][0]<newInterval[0])
            i+=1;
        intervals.insert(intervals.begin()+i,newInterval);
        if(i!=0)
            i-=1;
        for(int j=i+1;j<intervals.size();j+=1){
            if(intervals[i][1]>=intervals[j][0])
                intervals[i][1]=max(intervals[i][1],intervals[j][1]);
            else
                intervals[++i]=intervals[j];
        }
        intervals.erase(intervals.begin()+i+1,intervals.end());
        return intervals;
    }
};