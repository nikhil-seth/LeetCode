// 42. Trapping Rain Water
class Solution {
public:
    int trap(vector<int>& arr){
        ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
        stack<int> s;
        int ans=0;
        for(int i=0;i<arr.size();i++){
            while(!s.empty() && arr[s.top()]<=arr[i]){
                int x=s.top();
                s.pop();
                if(!s.empty()){
                    ans=ans+(min(arr[i],arr[s.top()])-arr[x])*(i-s.top()-1);
                }
            }
          //  cout<<ans<<' '<<s.size()<<endl;
            s.push(i);
        }
        return ans;
    }
};