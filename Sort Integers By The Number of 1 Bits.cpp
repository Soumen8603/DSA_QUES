vector<int> sortByBits(vector<int>& arr) {
        vector < pair<int, int>> vec;
        for (int i = 0; i < arr.size(); i++) {
            int count = 0;
            for (int j = 31; j >= 0; j--) {
                int bit = (arr[i] >> j) & 1;
                if (bit == 1)
                    count++;
            }
            vec.push_back({arr[i], count});
        }

        sort(vec.begin(), vec.end(),
             [](const std::pair<int, int>& a, const std::pair<int, int>& b) {
                 if (a.second != b.second) {
                     return a.second < b.second;
                 }

                 return a.first < b.first;
             });

        vector<int>ans;
        for(int i = 0;i < vec.size();i++){
            ans.push_back(vec[i].first);
        }
        return ans;
    }
