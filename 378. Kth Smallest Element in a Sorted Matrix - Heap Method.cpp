// 378. Kth Smallest Element in a Sorted Matrix
// Heap Method

class Solution {
public:
    struct data{
        int val,i,j;
        data(int a,int b,int c){
            val=a;
            i=b;
            j=c;
        }
    };
    struct dx{
        bool operator()(data &d1,data &d2){
            return d1.val>d2.val;
        }
    };
    int kthSmallest(vector<vector<int>>& matrix, int k){
        ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
        priority_queue<data,vector<data>,dx> pq;
        for(int i=0;i<matrix.size();i+=1)
            pq.push(data(matrix[i][0],i,0));
        data d(0,0,0);
        while(k--){
            d=pq.top();
            pq.pop();
            d.j+=1;
            if(d.j<matrix.size())
                pq.push(data(matrix[d.i][d.j],d.i,d.j));
        }
        return d.val;
    }
};
