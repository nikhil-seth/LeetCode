// 901. Online Stock Span

class StockSpanner {
    stack<pair<int,int>> s;
    int ch;
public:
    StockSpanner() {
        while(!s.empty())
            s.pop();
        ch=0;
        //ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
    }
    int next(int price) {
        ch++;
        while(!s.empty() && s.top().first<=price)
            s.pop();
        int ans;
        if(s.empty())
            ans=ch;
        else
            ans=(ch-s.top().second);
        s.push(make_pair(price,ch));
        return ans;
    }
};

/**
 * Your StockSpanner object will be instantiated and called as such:
 * StockSpanner* obj = new StockSpanner();
 * int param_1 = obj->next(price);
 */