// 992. Subarrays with K Different Integers

class Solution {
public:
    int subarraysWithKDistinct(vector<int>& A, int K){
        ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
        return fn(A,K)-fn(A,K-1);
    }
    int fn(vector<int> &A,int K){
        int ans=0;
        int ctr=0,n=A.size();
        vector<int> vis(n+1,0);
        for(int j=0,i=0;j<n;j+=1){
            if(!vis[A[j]]++) K--;
            while(K<0){
                if(!--vis[A[i]]) K++;
                i+=1;
            }
            ans+=j-i+1;
        }
        return ans;
    }
};
