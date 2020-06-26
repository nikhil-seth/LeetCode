// 60. Permutation Sequence

class Solution {
public:
    string getPermutation(int n, int k){
        ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
        string s;
        vector<int> v;
        int ans=1;
        for(int i=1;i<=n;i+=1){
            ans*=i;
            v.push_back(i);
        }
        ans/=n;
        k-=1;
        int j=n-1;
        while(j){
            int x=k/ans;
            //cout<<k<<' '<<ans<<endl;
            k-=x*ans;
            ans/=j;
            j--;
            s.push_back(v[x]+48);
            v.erase(v.begin()+x);
        }
        s.push_back(v[0]+48);
        return s;
    }
};