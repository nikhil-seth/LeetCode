// 1319. Number of Operations to Make Network Connected

class Solution {
public:
    vector<int> parent,size;
    int findset(int v){
        if(parent[v]==v) return v;
        return parent[v]=findset(parent[v]);
    }
    int makeConnected(int n, vector<vector<int>>& connections){
        ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
        parent=vector<int>(n);
        size=vector<int>(n,1);
        for(int i=0;i<n;i+=1)
            parent[i]=i;
        int ctr=0,a,b;
        for(auto x:connections){
            a=findset(x[0]);
            b=findset(x[1]);
            if(a==b)
                ctr+=1;
            else{
                if(size[a]<size[b])
                    swap(a,b);
                parent[b]=a;
                size[a]+=size[b];
            }
        }
        int k=0;
        for(int i=0;i<n;i+=1){
            if(parent[i]==i)
                k+=1;
        }
        if(ctr+1<k)
            return -1;
        return k-1;
    }
};
