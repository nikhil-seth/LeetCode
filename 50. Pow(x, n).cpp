// 50. Pow(x, n)

static auto io=[](){ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);return 0;}();
class Solution {
public:
    double fn(double x,long n){
        if(n==0)
            return 1;
        if(n%2==0){
            double d=fn(x,n/2);
            d*=d;
            return d;
        }
        else{
            double d=fn(x,n-1);
            d*=x;
            return d;
        }
    }
    double myPow(double x, int n){
        long n2=n;
        double d=fn(x,abs(n2));
        if(n<0)
            d=1/d;
        return d;
    }
};
