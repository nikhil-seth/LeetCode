// 374. Guess Number Higher or Lower

/** 
 * Forward declaration of guess API.
 * @param  num   your guess
 * @return       -1 if num is lower than the guess number
 *                1 if num is higher than the guess number
 *               otherwise return 0
 * int guess(int num);
 */
static auto io=[](){ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);return 0;}();
class Solution {
public:
    int guessNumber(int n){
        int lo=1,mid;
        while(lo<=n){
            mid=lo+(n-lo)/2;
            //cout<<mid<<' '<<guess(mid)<<endl;
            if(guess(mid)==0)
                return mid;
            else if(guess(mid)==-1)
                n=mid-1;
            else
                lo=mid+1;
        }
        return 1;
    }
};
