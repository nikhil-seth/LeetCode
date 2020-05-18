// 862. Shortest Subarray with Sum at Least K
class Solution {
public:
    int shortestSubarray(vector<int>& A, int K){
        ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
        int n=A.size();
        int ans=n+1;
        deque<int> dq;
        for(int i=0;i<n;i+=1){
            if(i>0)
                A[i]+=A[i-1];
            if(A[i]>=K) // Means starting seh bngya.
                ans=min(ans,i+1);
            while(dq.size()>0 && A[i]-A[dq.front()]>=K)
                ans=min(ans,i-dq.front()),dq.pop_front();
            while(dq.size()>0 && A[dq.back()]>=A[i])
                dq.pop_back();
            dq.push_back(i);
        }
        return ans<=n?ans:-1;
    }
};