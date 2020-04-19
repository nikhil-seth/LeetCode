// 1124. Longest Well-Performing Interval

class Solution {
public:
    int longestWPI(vector<int>& hours){
        ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
        stack<int> s;
        int n=hours.size(),res=0;
        int ps[n+1];
        ps[0]=0;
        for(int i=1;i<=n;i++){
            if(hours[i-1]>8)
                ps[i]=ps[i-1]+1;
            else
                ps[i]=ps[i-1]-1;
        }
        for(int i=0;i<=n;i++){
            if(s.empty() || ps[s.top()]>ps[i])
                s.push(i);
        }
        // We did first pass & made a monotonically decreasing array.
        for(int i=n;i>=0;i--){
            while(!s.empty() && (ps[i]-ps[s.top()])>0){
                res=max(res,i-s.top());
                s.pop();
            }
        }
        return res;
    }
};
