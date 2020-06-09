// 11. Container With Most Water

class Solution {
public:
    int maxArea(vector<int>& height){
        ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
        int i,j,n;
        int ans=0;
        i=0,n=height.size(),j=n-1;
        while(i<j){
            ans=max(ans,(j-i)*min(height[j],height[i]));
            if(height[j]>height[i])
                i+=1;
            else
                j-=1;
        }
        return ans;
    }
};
