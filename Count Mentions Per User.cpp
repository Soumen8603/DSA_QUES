vector<int> countMentions(int numberOfUsers,
                              vector<vector<string>>& events) {
        ranges::sort(events,
                     [](const vector<string>& a, const vector<string>& b) {
                         int timestampA = stoi(a[1]);
                         int timestampB = stoi(b[1]);
                         if (timestampA == timestampB) {
                             return a[0][2] < b[0][2];
                         }
                         return timestampA < timestampB;
                     });

        vector<int> mentionCounts(numberOfUsers, 0);
        vector<int> offlineUntilTime(numberOfUsers, 0);
        int pendingAllMentions = 0;

        for (const auto& event : events) {
            string eventType = event[0];
            int currentTime = stoi(event[1]);
            string eventData = event[2];

            if (eventType[0] == 'O') {
                int userId = stoi(eventData);
                offlineUntilTime[userId] = currentTime + 60;
            } else if (eventData[0] == 'A') {
                pendingAllMentions++;
            } else if (eventData[0] == 'H') {
                for (int userId = 0; userId < numberOfUsers; ++userId) {
                    if (offlineUntilTime[userId] <= currentTime) {
                        ++mentionCounts[userId];
                    }
                }
            } else {
                stringstream stringStream(eventData);
                string userIdToken;
                while (stringStream >> userIdToken) {
                    int userId = stoi(userIdToken.substr(2));
                    mentionCounts[userId]++;
                }
            }
        }

        if (pendingAllMentions > 0) {
            for (int userId = 0; userId < numberOfUsers; ++userId) {
                mentionCounts[userId] += pendingAllMentions;
            }
        }

        return mentionCounts;
    }
