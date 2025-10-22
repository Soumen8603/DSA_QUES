class Solution {
private:
    class Event {
        public:
        int x;
        int sign;
        
        Event(int x, int sign) {
            this->x = x;
            this->sign = sign;
        }
    };

public:
    int maxFrequency(vector<int>& nums, int k, int numOperations) {
        sort(nums.begin(), nums.end());
        int n = nums.size();
        vector<Event> events;
        set<int> criticalPoints;
        unordered_map<int, int> freq;
        for (int num : nums) {
            freq[num]++;
            int s = num - k;
            int e = num + k;
            events.emplace_back(s, 1);
            events.emplace_back(e+1, -1);
            criticalPoints.insert(s);
            criticalPoints.insert(e + 1);
            criticalPoints.insert(num);
        }
        sort(events.begin(), events.end(),
                  [](const Event& a, const Event& b) {
                      if (a.x != b.x) {
                          return a.x < b.x;
                      }
                      return a.sign < b.sign;
                  });
        int maxFreq = 1, overlapCount = 0, eventId = 0;
        for (const int& element : criticalPoints) {
            while (eventId < events.size() && events[eventId].x <= element) {
                overlapCount += (events[eventId].sign == 1) ? 1 : -1;
                eventId++;
            }
            int currentFreq = freq[element];
            int currentPossibleFreq =
                currentFreq +
                min(numOperations, max(0, overlapCount - currentFreq));
            maxFreq = max(maxFreq, currentPossibleFreq);
        }
        return maxFreq;
    }
};
