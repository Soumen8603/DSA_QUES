 int canCompleteCircuit(vector<int>& gas, vector<int>& cost) {
        int sum = 0;
        int collected = 0;
        int start = 0;
        int n = gas.size();
        for (int i = 0; i < n; i++) {
            sum += (gas[i] - cost[i]);
            collected += (gas[i] - cost[i]);
            if (collected < 0) {
                collected = 0;
                start = i + 1;
            }
        }

        if (sum >= 0) {
            return start;
        } else {
            return -1;
        }
    }
