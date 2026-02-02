class Solution {
public:
    typedef long long ll;
    typedef pair<ll, int> P;

    long long minimumCost(vector<int>& nums, int k, int dist) {
        int n = nums.size();
        set<P> kMinimum, remaining;
        ll currentSum = 0;
        int targetSize = k - 1;

        for (int i = 1; i <= dist + 1; ++i) {
            kMinimum.insert({nums[i], i});
            currentSum += nums[i];
        }

        while (kMinimum.size() > targetSize) {
            P largest = *kMinimum.rbegin();
            currentSum -= largest.first;
            remaining.insert(largest);
            kMinimum.erase(prev(kMinimum.end()));
        }

        ll minTotalCost = currentSum;

        for (int i = dist + 2; i < n; ++i) {
            P out = {nums[i - dist - 1], i - dist - 1};
            if (kMinimum.count(out)) {
                currentSum -= out.first;
                kMinimum.erase(out);
            } else {
                remaining.erase(out);
            }

            P in = {nums[i], i};
            kMinimum.insert(in);
            currentSum += in.first;

            P toRemaining = *kMinimum.rbegin();
            currentSum -= toRemaining.first;
            remaining.insert(toRemaining);
            kMinimum.erase(prev(kMinimum.end()));

            if (kMinimum.size() < targetSize) {
                P toKMin = *remaining.begin();
                currentSum += toKMin.first;
                kMinimum.insert(toKMin);
                remaining.erase(remaining.begin());
            }

            minTotalCost = min(minTotalCost, currentSum);
        }

        return minTotalCost + nums[0];
    }
};
