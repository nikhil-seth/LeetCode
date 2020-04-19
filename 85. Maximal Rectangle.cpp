// 85. Maximal Rectangle

class Solution {
public:
    int maximalRectangle(vector<vector<char>>& matrix){
        ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
        int n,m;
        n=matrix.size();
        if(n==0)
            return 0;
        m=matrix[0].size();
        int arr[m],ans=0;
        memset(arr,0,sizeof(arr));
        stack<int> s;
        for(int l=0;l<n;l++){
            for(int j=0;j<m;j++){
                if(matrix[l][j]=='1')
                    arr[j]+=1;
                else
                    arr[j]=0;
            }
            for(int i=0;i<m;i++){
                //cout<<i<<' '<<arr[i]<<endl;
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
                ans=max(ans,(s.empty()?m:(m-s.top()-1))*arr[x]);
            }
            //cout<<ans<<endl;
        }
        return ans;
    }
};