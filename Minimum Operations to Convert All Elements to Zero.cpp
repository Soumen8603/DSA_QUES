class Solution {
private:
    const int INF = numeric_limits<int>::max();
    vector<int> seg_tree;
    int n;
    vector<vector<int>> val_to_indices;
    unordered_map<long long, int> memo;

    long long getKey(int l, int r) {
        return (static_cast<long long>(l) << 32) | static_cast<long long>(r);
    }

    void build_tree(const vector<int>& nums, int node, int l, int r) {
        if (l == r) {
            seg_tree[node] = (nums[l] == 0) ? INF : nums[l];
            return;
        }
        int mid = l + (r - l) / 2;
        build_tree(nums, 2 * node + 1, l, mid);
        build_tree(nums, 2 * node + 2, mid + 1, r);
        seg_tree[node] = min(seg_tree[2 * node + 1], seg_tree[2 * node + 2]);
    }

    int query_tree(int node, int l, int r, int query_l, int query_r) {
        if (l > query_r || r < query_l) {
            return INF;
        }
        if (l >= query_l && r <= query_r) {
            return seg_tree[node];
        }
        int mid = l + (r - l) / 2;
        int left_min = query_tree(2 * node + 1, l, mid, query_l, query_r);
        int right_min = query_tree(2 * node + 2, mid + 1, r, query_l, query_r);
        return min(left_min, right_min);
    }

    int solve(int l, int r) {
        if (l > r) {
            return 0;
        }

        long long key = getKey(l, r);
        if (memo.count(key)) {
            return memo[key];
        }

        int min_val = query_tree(0, 0, n - 1, l, r);

        if (min_val == INF) {
            return memo[key] = 0;
        }

        int ops = 1;
        
        vector<int>& indices = val_to_indices[min_val];
        
        auto it_start = lower_bound(indices.begin(), indices.end(), l);
        auto it_end = upper_bound(it_start, indices.end(), r);

        int last_split_index = l - 1;
        for (auto it = it_start; it != it_end; ++it) {
            int current_index = *it;
            ops += solve(last_split_index + 1, current_index - 1);
            last_split_index = current_index;
        }

        ops += solve(last_split_index + 1, r);

        return memo[key] = ops;
    }

public:
    int minOperations(vector<int>& nums) {
        n = nums.size();
        if (n == 0) return 0;

        val_to_indices.assign(100001, vector<int>());
        
        memo.clear();

        for (int i = 0; i < n; ++i) {
            if (nums[i] > 0) {
                val_to_indices[nums[i]].push_back(i);
            }
        }

        seg_tree.resize(4 * n);
        build_tree(nums, 0, 0, n - 1);

        int total_ops = 0;
        int current_block_start = 0;

        for (int i = 0; i < n; ++i) {
            if (nums[i] == 0) {
                if (current_block_start < i) {
                    total_ops += solve(current_block_start, i - 1);
                }
                current_block_start = i + 1;
            }
        }

        if (current_block_start < n) {
            total_ops += solve(current_block_start, n - 1);
        }

        return total_ops;
    }
};
