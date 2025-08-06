   vector<int> seg;
    void build(int ind, vector<int>& baskets, int low, int high) {
        if (low == high) {
            seg[ind] = baskets[low];
            return;
        }
        int mid = (low + high) / 2;
        build(2 * ind + 1, baskets, low, mid);
        build(2 * ind + 2, baskets, mid + 1, high);
        seg[ind] = max(seg[2 * ind + 1], seg[2 * ind + 2]);
    }
    int find_unplaced(int fruit, int index, int high, int low) {

        if (fruit > seg[index]) {
            return -1;
        }
        if (low == high) {
            return low;
        }
        int mid = (low + high) / 2;
        int left = find_unplaced(fruit, index * 2 + 1, mid, low);
        if (left != -1)
            return left;
        return find_unplaced(fruit, index * 2 + 2, high, mid + 1);
    }

    void update(int ind, int low, int high, int pos, int val) {
        if (low == high) {
            seg[ind] = val;
            return;
        }
        int mid = (low + high) / 2;
        if (pos <= mid) {
            update(2 * ind + 1, low, mid, pos, val);
        } else {
            update(2 * ind + 2, mid + 1, high, pos, val);
        }
        seg[ind] = max(seg[2 * ind + 1], seg[2 * ind + 2]);
    }

public:
    int numOfUnplacedFruits(vector<int>& fruits, vector<int>& baskets) {

        int n = baskets.size();
        seg.resize(4 * n);
        build(0, baskets, 0, n - 1);
        int count = 0;
        for (int i = 0; i < fruits.size(); i++) {
            int index = find_unplaced(fruits[i], 0, n - 1, 0);
            if (index == -1) {
                count++;
            } else {
                update(0, 0, n - 1, index, INT_MIN);
            }
        }
        return count;
    }
