class Solution {
private:
    int precedence(char op) {
        if (op == '+' || op == '-')
            return 1;
        return 0;
    }

    std::string infinixtopostfix(std::string s) {
        std::stack<char> st;
        std::string output = "";
        for (int i = 0; i < s.size(); i++) {
            char c = s[i];

            if (isspace(c)) {
                continue;
            }

            if (isdigit(c)) {
                std::string number;
                while (i < s.size() && isdigit(s[i])) {
                    number += s[i];
                    i++;
                }
                i--;
                output += number;
                output += ' ';
            } else if (c == '(') {
                st.push(c);
            } else if (c == ')') {
                while (!st.empty() && st.top() != '(') {
                    output += st.top();
                    output += ' ';
                    st.pop();
                }
                if (!st.empty()) st.pop();
            } else {
                bool is_unary = false;
                if (c == '-') {
                    int j = i - 1;
                    while (j >= 0 && isspace(s[j])) {
                        j--;
                    }
                    if (j < 0 || s[j] == '(' || s[j] == '+' || s[j] == '-') {
                        is_unary = true;
                    }
                }

                if (is_unary) {
                    output += "0 ";
                }

                while (!st.empty() && precedence(st.top()) >= precedence(c)) {
                    output += st.top();
                    output += ' ';
                    st.pop();
                }
                st.push(c);
            }
        }

        while (!st.empty()) {
            output += st.top();
            output += ' ';
            st.pop();
        }
        return output;
    }

    int evaluatepostfix(std::string postfix) {
        std::stack<long long> st;
        std::stringstream ss(postfix);
        std::string token;
        while (ss >> token) {
            if (isdigit(token[0]) || (token.length() > 1)) {
                st.push(stoll(token));
            } else {
                if (st.size() < 2) continue;
                long long b = st.top(); st.pop();
                long long a = st.top(); st.pop();
                if (token == "+")
                    st.push(a + b);
                else if (token == "-")
                    st.push(a - b);
            }
        }
        return st.empty() ? 0 : st.top();
    }

public:
    int calculate(std::string s) {
        std::string postfix = infinixtopostfix(s);
        return evaluatepostfix(postfix);
    }
};
