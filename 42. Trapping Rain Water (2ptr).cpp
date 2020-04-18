// 42. Trapping Rain Water
class Solution {
public:
    int trap(vector<int>& h){
        ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
        int l=0,r=h.size()-1,lmax,rmax;
        lmax=rmax=0;
        int ans=0;
        while(l<r){
            if(h[l]<=h[r]){
                if(h[l]>=lmax)
                    lmax=h[l];
                else
                    ans+=(lmax-h[l]);
                l+=1;
            }
            else{
                if(h[r]>=rmax)
                    rmax=h[r];
                else
                    ans+=(rmax-h[r]);
                r-=1;
            }
        }
        return ans;
    }
};