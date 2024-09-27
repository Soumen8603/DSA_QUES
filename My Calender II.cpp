class MyCalendarTwo {
public:
map<int,int>mp;
    MyCalendarTwo() {
        
    }
    
    bool book(int start, int end) {
        mp[start]++;
        mp[end]--;
        int sum = 0;
        for(auto &[first,sec]:mp){
            sum+=sec;
            if(sum > 2){
                mp[start]--;
                mp[end]++;
                return false;
            }
        }
        return true;
    }
};
