class MinStack {
    map<int,int>mp;
    stack<int>st;
public:
    MinStack() {
        
    }
    
    void push(int val) {
        st.push(val);
        mp[val]++;
    }
    
    void pop() {
        int val = st.top();
        mp[val]--;
        if(mp[val] == 0){
        mp.erase(val);
        }
        st.pop();
    }
    
    int top() {
        return st.top();
    }
    
    int getMin() {
        auto firstElement = mp.begin();
        return firstElement->first;
    }
};

