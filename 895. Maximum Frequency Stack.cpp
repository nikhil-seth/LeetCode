// 895. Maximum Frequency Stack

class FreqStack {
    unordered_map<int,int> freq;
    unordered_map<int,stack<int>> m;
    int maxFreq=0;
public:
    FreqStack() {
        ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
        freq.clear();
        m.clear();
        maxFreq=0;
    }
    void push(int x) {
        maxFreq=max(maxFreq,++freq[x]);
        m[freq[x]].push(x);
    }
    int pop() {
        int k=m[maxFreq].top();
        --freq[k];
        m[maxFreq].pop();
        if(m[maxFreq].size()==0)
            maxFreq-=1;
        return k;
    }
};
/**
 * Your FreqStack object will be instantiated and called as such:
 * FreqStack* obj = new FreqStack();
 * obj->push(x);
 * int param_2 = obj->pop();
 */