// 1201. Ugly Number III

class Solution {
public:
    int nthUglyNumber(int n, long a, long b, long c){
        if(a==1 || b==1 || c==1)
            return n;
        long lo=1,hi=2*1e9,mid,x,ans;
        long ab,bc,ac,abc;
        ab=(a*b)/__gcd(a,b);
        bc=(c*b)/__gcd(c,b);
        ac=(a*c)/__gcd(a,c);
        abc=(a*bc)/__gcd(a,bc);
        while(lo<=hi){
            mid=lo+(hi-lo)/2;
            x=mid/a + mid/b+mid/c;
            x=x-mid/ab-mid/bc-mid/ac+mid/abc;
            if(x<n)
                lo=mid+1;
            else{
                ans=mid;
                hi=mid-1;
            }
        }
        return ans;
    }
};
