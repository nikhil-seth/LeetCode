// 1361. Validate Binary Tree Nodes

class Solution {
public:
    bool dfs(vector<vector<int>> &adj,vector<bool> &vis,int v){
        vis[v]=1;
        for(auto x:adj[v]){
            if(vis[x]) return 0;
            if(!dfs(adj,vis,x)) return 0;
        }
        return 1;
    }
    bool validateBinaryTreeNodes(int n, vector<int>& leftChild, vector<int>& rightChild){
        ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
        vector<vector<int>> adj(n);
        vector<bool> vis(n,0);
        for(int i=0;i<n;i+=1){
            if(leftChild[i]!=-1){
                adj[i].push_back(leftChild[i]);
                vis[leftChild[i]]=1;
            }
            if(rightChild[i]!=-1){
                adj[i].push_back(rightChild[i]);
                vis[rightChild[i]]=1;
            }
        }
        int h=-1;
        for(int i=0;i<n;i+=1){
            if(!vis[i]){
                if(h!=-1) return 0;
                h=i;
            }
        }
        if(h==-1) return 0;
        fill(vis.begin(),vis.end(),0);
        if(!dfs(adj,vis,h)) return 0;
        for(int i=0;i<n;i+=1){
            if(!vis[i]) return 0;
        }
        return 1;
    }
};
        