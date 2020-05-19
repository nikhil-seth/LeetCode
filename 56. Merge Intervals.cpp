// 56. Merge Intervals

class Solution {
public:
    static bool cmp(const vector<int> &a,vector<int> &b){
        if(a[0]==b[0])
            return a[1]<b[1];
        return a[0]<b[0];
    }
    vector<vector<int>> merge(vector<vector<int>>& iv){
        ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
        vector<vector<int>> v;
        int n=iv.size();
        if(!n) return v;
        sort(iv.begin(),iv.end(),cmp);
        v.push_back(iv[0]);
        int idx=0;
        int i=0;
        for(int j=1;j<n;j+=1){
            if(iv[j][0]<=iv[i][1]){
                if(iv[j][1]>iv[i][1])
                    i=j;
            }
            else{
                v[idx++][1]=iv[i][1];
                i=j;
                v.push_back(iv[j]);
            }
        }
        v[idx][1]=iv[i][1];
        return v;
    }
};
        

        
    