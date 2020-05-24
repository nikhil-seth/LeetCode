// 295. Find Median from Data Stream

class MedianFinder {
public:
    /** initialize your data structure here. */
    priority_queue<int> lo;
    priority_queue<int,vector<int>,greater<int>> hi;
    double d;
    MedianFinder(){
        ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
    }
    void addNum(int num){
        lo.push(num);
        hi.push(lo.top());
        lo.pop(); // to balance.
        if(lo.size()<hi.size())
            lo.push(hi.top()),hi.pop();
        // We always keep element in lo
    }
    double findMedian(){
        if((lo.size()+hi.size())%2)
            return lo.top();
        else{
            d=lo.top()+hi.top();
            d/=2;
            return d;
        }
    }
};
/**
 * Your MedianFinder object will be instantiated and called as such:
 * MedianFinder* obj = new MedianFinder();
 * obj->addNum(num);
 * double param_2 = obj->findMedian();
 */