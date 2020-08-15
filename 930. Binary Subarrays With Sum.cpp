// 930. Binary Subarrays With Sum

class Solution {
public:
    int numSubarraysWithSum(vector<int>& A, int S){
        ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
        return fn(A,S)-(S==0?0:fn(A,S-1));
    }
    int fn(vector<int> &A,int S){
        int i,j;
        int ans=0;
        for(i=j=0;j<A.size();j+=1){
            if(A[j]) S--;
            while(S<0)
                if(A[i++]) S++;
            ans+=(j-i+1);
        }
        return ans;
    }
};
