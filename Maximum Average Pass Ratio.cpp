double maxAverageRatio(vector<vector<int>>& classes, int extraStudents) {
        priority_queue<pair<double, int>> passRatio;
        for (int i = 0; i < classes.size(); i++) {
            double ratio = ((double)(classes[i][0] + 1) / (classes[i][1] + 1) -
                            (double)(classes[i][0]) / (classes[i][1]));
            passRatio.push({ratio, i});
        }

        while (extraStudents > 0) {
            auto top = passRatio.top();
            passRatio.pop();
            int index = top.second;
            classes[index][0] = classes[index][0] + 1;
            classes[index][1] = classes[index][1] + 1;
            extraStudents--;
            double ratio =
                ((double)(classes[index][0] + 1) / (classes[index][1] + 1) -
                 ((double)classes[index][0]) / (classes[index][1]));
            passRatio.push({ratio, index});
        }

        double res = 0;
        for (int i = 0; i < classes.size(); i++) {
            res += ((double)classes[i][0] / classes[i][1]);
        }
        int n = classes.size();
        return res / n;
    }
