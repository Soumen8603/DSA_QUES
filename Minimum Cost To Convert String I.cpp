long long minimumCost(string source, string target, vector<char>& original, vector<char>& changed, vector<int>& cost) {
        const int INF = 1 << 29;
        int graph[26][26];

        for (int i = 0; i < 26; ++i) {
            fill(begin(graph[i]), end(graph[i]), INF);
            graph[i][i] = 0;
        }

        for (int i = 0; i < original.size(); ++i) {
            int fromChar = original[i] - 'a';
            int toChar = changed[i] - 'a';
            int transformCost = cost[i];
            graph[fromChar][toChar] = min(graph[fromChar][toChar], transformCost);
        }

        for (int intermediate = 0; intermediate < 26; ++intermediate) {
            for (int start = 0; start < 26; ++start) {
                for (int end = 0; end < 26; ++end) {
                    graph[start][end] = min(graph[start][end],
                                            graph[start][intermediate] + graph[intermediate][end]);
                }
            }
        }

        long long totalCost = 0;
        int stringLength = source.length();

        for (int i = 0; i < stringLength; ++i) {
            int sourceChar = source[i] - 'a';
            int targetChar = target[i] - 'a';

            if (sourceChar != targetChar) {
                if (graph[sourceChar][targetChar] >= INF) {
                    return -1;
                }
                totalCost += graph[sourceChar][targetChar];
            }
        }

        return totalCost;
    }
