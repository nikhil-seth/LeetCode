// 907. Sum of Subarray Minimums

class Solution {
public:
    int sumSubarrayMins(vector<int>& A){
        int n=A.size();
        vector<int> ps(n),ns(n);
        stack<int> s;
        long long ans=0,x;
        for(int i=0;i<n;i+=1){
            while(!s.empty() && A[s.top()]>=A[i])
                s.pop();
            if(s.empty())
                ps[i]=-1;
            else
                ps[i]=s.top();
            s.push(i);
        }
        while(!s.empty()) s.pop();
        for(int i=n-1;i>=0;i-=1){
            while(!s.empty() && A[s.top()]>A[i])
                s.pop();
            if(s.empty())
                ns[i]=n;
            else
                ns[i]=s.top();
            s.push(i);
        }
        for(int i=0;i<n;i+=1){
            x=((((i-ps[i])*(ns[i]-i))%1000000007)*A[i])%1000000007;
            ans+=x;
            ans%=1000000007;
        }
        return ans;
    }
};
