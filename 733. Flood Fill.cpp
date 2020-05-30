// 733. Flood Fill

class Solution {
public:
    vector<vector<int>> floodFill(vector<vector<int>>& image, int sr, int sc, int newColor){
        ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
        int n=image.size(),m=image[0].size();
        int d[4][2]={{1,0},{-1,0},{0,1},{0,-1}};
        if(newColor==image[sr][sc])
            return image;
        int prev_color=image[sr][sc],x,y;
        queue<pair<int,int>> q;
        q.push({sr,sc});
        image[sr][sc]=newColor;
        while(!q.empty()){
            sr=q.front().first,sc=q.front().second;
            q.pop();
            for(auto v:d){
                x=sr+v[0],y=sc+v[1];
                if(x<n && x>=0 && y<m && y>=0 && image[x][y]==prev_color)
                    image[x][y]=newColor,q.push({x,y});
            }
        }
        return image;
    }
};

            