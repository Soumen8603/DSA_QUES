 int findMinDifference(vector<string>& timePoints) {
        vector<int>minutes;
        for (const auto& timePoint : timePoints) {
        stringstream ss(timePoint);
        string hourStr, minuteStr;
        char delimiter = ':';

        getline(ss, hourStr, delimiter);
        getline(ss, minuteStr);

        int hours = stoi(hourStr);
        int minutesInDay = hours * 60 + stoi(minuteStr);
        minutes.push_back(minutesInDay);
    }
   sort(minutes.begin(), minutes.end());

   int minDifference = INT_MAX;
    int n = minutes.size();

   
    for (int i = 0; i < n - 1; ++i) {
        minDifference = min(minDifference, minutes[i + 1] - minutes[i]);
    }

    // Check the difference between the last and the first time
    minDifference = min(minDifference, (1440 - minutes.back() + minutes.front()));

    return minDifference;

}
