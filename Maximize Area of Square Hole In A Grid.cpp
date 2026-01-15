int getMaxGap(vector<int>& bars) {
        if (bars.empty()) return 2; 
        
        sort(bars.begin(), bars.end());
        
        int maxConsecutive = 1;
        int currentConsecutive = 1;
        
        for (int i = 1; i < bars.size(); i++) {
            if (bars[i] == bars[i-1] + 1) {
                currentConsecutive++;
            } else {
                maxConsecutive = max(maxConsecutive, currentConsecutive);
                currentConsecutive = 1;
            }
        }
        maxConsecutive = max(maxConsecutive, currentConsecutive);
        
       
        return maxConsecutive + 1;
    }
public:
    int maximizeSquareHoleArea(int n, int m, vector<int>& hBars, vector<int>& vBars) {
        int maxHGap = getMaxGap(hBars);
        int maxVGap = getMaxGap(vBars);
        
        
        long long side = min(maxHGap, maxVGap);
        
        return (int)(side * side);
    }
