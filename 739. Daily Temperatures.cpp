// 739. Daily Temperatures

class Solution {
public:
    vector<int> dailyTemperatures(vector<int>& T) {
        ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);

        int n=T.size();
        vector<int> ans(n);
        stack<int> s;
        for(int i=n-1;i>=0;i--){
            while(!s.empty() && T[s.top()]<=T[i])
                s.pop();
            if(!s.empty())
                ans[i]=(s.top()-i);
            else
                ans[i]=0;
            s.push(i);
        }
        return ans;
    }
};