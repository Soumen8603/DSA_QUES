int countCoveredBuildings(int n, vector<vector<int>>& buildings) {
        vector<vector<int>>rows(n+1),cols(n+1);
        for(auto &b : buildings){
            int r = b[0],c = b[1];
            rows[r].push_back(c);
            cols[c].push_back(r);
        }
        for(int i = 1;i < n;i++){
            if(!rows[i].empty())sort(rows[i].begin(),rows[i].end());
            if(!cols[i].empty())sort(cols[i].begin(),cols[i].end());
        }
        int count = 0;
        for(auto &b : buildings){
            int r = b[0],c = b[1];
            if(r <= 1 || r >= n || c <= 1 || c >= n)continue;
            auto &colList = cols[c];
            auto itc = lower_bound(colList.begin(),colList.end(),r);
            int posc = int(itc - colList.begin());
            bool hasAbove = (posc > 0);
            bool hasBelow = (posc + 1 < (int)colList.size());

            auto &rowList = rows[r];
            auto itr = lower_bound(rowList.begin(),rowList.end(),c);
            int posr = int(itr - rowList.begin());
            bool hasLeft = (posr > 0);
            bool hasRight = (posr + 1 < (int)rowList.size());
            if(hasAbove && hasBelow && hasLeft && hasRight)count++;

        }
        return count;
    }
