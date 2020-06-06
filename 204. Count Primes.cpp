// 204. Count Primes
class Solution {
public:
    int countPrimes(int n){
        if(n<3)
            return 0;
        int ctr=1;
        vector<bool> v(n,0);
        for(long i=3;i<n;i+=2){
            if(v[i]==0){
                ctr+=1;
                for(long j=i*i;j<n;j+=(2*i))
                    v[j]=1;
            }
        }
        return ctr;
    }
};