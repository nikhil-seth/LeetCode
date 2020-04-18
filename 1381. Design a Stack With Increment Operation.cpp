// 1381. Design a Stack With Increment Operation

class CustomStack {
    int *arr,top,ms;
public:
    CustomStack(int maxSize){
        arr=new int[maxSize];
        ms=maxSize;
        top=-1;
        ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
    }
    void push(int x){
        if(top==ms-1)
            return;
        arr[++top]=x;
    }
    int pop(){
        if(top==-1)
            return -1;
        return arr[top--];
    }
    void increment(int k, int val) {
        for(int i=0;i<min(k,top+1);i++)
            arr[i]+=val;
    }
};

/**
 * Your CustomStack object will be instantiated and called as such:
 * CustomStack* obj = new CustomStack(maxSize);
 * obj->push(x);
 * int param_2 = obj->pop();
 * obj->increment(k,val);
 */