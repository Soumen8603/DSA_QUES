class Solution {
public:
    int countTrapezoids(vector<vector<int>>& points) {
        long long MOD = 1e9 + 7;

        unordered_map<int, int> y_counts;
        for (const auto& p : points) {
            y_counts[p[1]]++;
        }

        long long total_trapezoids = 0;
        long long combinations_so_far = 0;

        for (const auto& entry : y_counts) {
            int count = entry.second;
            if (count >= 2) {
                long long combinations_on_this_level =
                    (long long)count * (count - 1) / 2;

                total_trapezoids =
                    (total_trapezoids +
                     combinations_on_this_level * combinations_so_far) %
                    MOD;

                combinations_so_far =
                    (combinations_so_far + combinations_on_this_level) % MOD;
            }
        }

        return (int)total_trapezoids;
    }
};
