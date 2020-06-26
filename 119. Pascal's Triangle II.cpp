// 119. Pascal's Triangle II

class Solution {
public:
    vector<int> getRow(int rowIndex){
        ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
        vector<int> v(rowIndex+1,0);
        v[0]=1;
        for(int i=1;i<=rowIndex;i+=1){
            for(int j=1,t1=1,t2;j<=i;j+=1){
                t2=v[j];
                v[j]+=t1;
                t1=t2;
            }
        }
        return v;
    }
};
