bool isValid(string s) {
        stack<char> open;
        int n = s.size();
        for (int i = 0; i < n; i++) {
            if (s[i] == ')') {
                if (!open.empty() && open.top() == '(') {
                    open.pop();
                } else {
                    return false;
                }
            } else if (s[i] == ']') {
                if (!open.empty() && open.top() == '[') {
                    open.pop();
                } else {
                    return false;
                }
            } else if (s[i] == '}') {
                if (!open.empty() && open.top() == '{') {
                    open.pop();
                } else {
                    return false;
                }
            } else {
                open.push(s[i]);
            }
        }
        return open.empty();
    }
