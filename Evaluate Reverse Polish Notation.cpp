class Solution {
private:
    bool issymbol(const string &c){
        return (c == "+" || c == "-" || c == "*" || c == "/");
    }

    int calculate(int num1, int num2, const string &c){
        if(c == "*") return num1 * num2;
        else if(c == "+") return num1 + num2;
        else if(c == "-") return num1 - num2;
        else return num1 / num2;
    }

public:
    int evalRPN(vector<string>& tokens) {
        stack<int> st;
        for (string &tok : tokens) {
            if (!issymbol(tok)) {
                st.push(stoi(tok));
            } else {
                int b = st.top(); st.pop();
                int a = st.top(); st.pop();
                st.push(calculate(a, b, tok));
            }
        }
        return st.top();
    }
};
