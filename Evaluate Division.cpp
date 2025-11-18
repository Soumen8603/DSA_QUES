class Solution {
private:
    unordered_map<string, unordered_map<string, double>>
    build(vector<vector<string>>& equations, vector<double>& values) {
        unordered_map<string, unordered_map<string, double>>gr;
            for (int i = 0; i < equations.size(); i++) {
            string dividend = equations[i][0];
            string divisor = equations[i][1];
            double value = values[i];
            gr[dividend][divisor] = value;
            gr[divisor][dividend] = 1 / value;
        }
        return gr;
    }
    void dfs(string node, string& dest,
             unordered_map<string, unordered_map<string, double>> gr,
             unordered_set<string> vis, double& value, double temp) {
                if(vis.find(node) != vis.end())return;
                vis.insert(node);
                if(node == dest){
                    value = temp;
                    return;
                }
                for(auto ne : gr[node]){
                    dfs(ne.first,dest,gr,vis,value,temp * ne.second);
                }
             }

public:
    vector<double> calcEquation(vector<vector<string>>& equations,
                                vector<double>& values,
                                vector<vector<string>>& queries) {
        unordered_map<string, unordered_map<string, double>> gr =
            build(equations, values);
        vector<double> ans; 
        for (int i = 0; i < queries.size(); i++) {
            string dividend = queries[i][0];
            string divisor = queries[i][1];
            if (gr.find(dividend) == gr.end() || gr.find(divisor) == gr.end()) {
                ans.push_back(-1.0);
                continue;
            }
            double value = -1.0, temp = 1.0;
            unordered_set<string> vis;
            dfs(dividend, divisor, gr, vis, value, temp);
            ans.push_back(value);
        }
        return ans;
    }
};
