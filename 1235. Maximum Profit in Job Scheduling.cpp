//1235. Maximum Profit in Job Scheduling
int _IO=[](){
    std::ios::sync_with_stdio(0);
    cin.tie(0); //cout.tie(0);
    return 0;
}();
class Solution {
public:
    int jobScheduling(vector<int>& startTime, vector<int>& endTime, vector<int>& profit) {
        const int n=startTime.size();
        vector<int> arr(n);
        for(int i=0;i<n;i++)
            arr[i]=i;
        sort(arr.begin(),arr.end(),[&endTime](int a,int b){
            return endTime[a]<endTime[b];
        });
        map<int,int> dp;
        for(auto ix:arr){
            int st=startTime[ix];
            auto f=dp.lower_bound(-st);
            int val=profit[ix];
            if(f!=dp.end())
                val+=f->second;
            int et=-endTime[ix];
            f=dp.lower_bound(et);
            if(f!=dp.end() && f->second>=val)
                continue;
            dp[et]=val;
        }
        return (dp.begin()->second);
    }
};
        