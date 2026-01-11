class Solution {
private:
    int lHistogram(vector<int> vec) {
        stack<int> st;
        int n = vec.size();
        int maxArea = 0;
        for (int i = 0; i < n; i++) {
            while (!st.empty() && vec[st.top()] > vec[i]) {
                int ele = st.top();
                st.pop();
                int pse = st.empty() ? -1 : st.top();
                int nse = i;
                maxArea = max(maxArea, vec[ele] * (nse - pse - 1));
            }
            st.push(i);
        }
        while (!st.empty()) {
            int ele = st.top();
            st.pop();
            int pse = st.empty() ? -1 : st.top();
            int nse = n;
            maxArea = max(maxArea, vec[ele] * (nse - pse - 1));
        }
        return maxArea;
    }

public:
    int maximalRectangle(vector<vector<char>>& matrix) {
        int m = matrix.size(), n = matrix[0].size();
        vector<vector<int>> prefixSum(m, vector<int>(n, 0));
        for (int i = 0; i < n; i++) {
            int sum = 0;
            for (int j = 0; j < m; j++) {
                if(matrix[j][i] == '1'){
                    sum += 1;
                }
                else{
                    sum = 0;
                }
                prefixSum[j][i] = sum;
            }
        }

        int maxArea = 0;
        for (int i = 0; i < m; i++) {
            maxArea = max(maxArea, lHistogram(prefixSum[i]));
        }
        return maxArea;
    }
};
