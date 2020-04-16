// 84. Largest Rectangle in Histogram

class Solution {
public:
    int largestRectangleArea(vector<int>& arr) {
        ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
        int n=arr.size();
        stack<int> s;
        int ans=0;
        for(int i=0;i<n;i++){
            while(!s.empty() && arr[s.top()]>=arr[i]){
                int x=s.top();
                s.pop();
                ans=max(ans,(s.empty()?i:(i-s.top()-1))*arr[x]);
            }
            s.push(i);
        }
        while(!s.empty()){
            int x=s.top();
            s.pop();
            ans=max(ans,(s.empty()?(n):(n-s.top()-1))*arr[x]);
        }
        return ans;
    }
};