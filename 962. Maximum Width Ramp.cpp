// 962. Maximum Width Ramp
class Solution {
public:
    int maxWidthRamp(vector<int>& A) {
        ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
        stack<int> s;
        int ans=0;
        for(int i=0;i<A.size();i++){
            if(s.empty() || A[s.top()]>A[i])
                s.push(i);
        }
        for(int i=A.size()-1;i>=0;i--){
            while(!s.empty() && A[s.top()]<=A[i]){
                ans=max(ans,i-s.top());
                s.pop();
            }
        }
        return ans;
    }
};