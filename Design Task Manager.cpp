class TaskManager {
    unordered_map<int, set<pair<int, int>>> usermap;
    unordered_map<int, set<pair<int, int>>> taskmap;
    map<int, set<pair<int, int>>> priormap;

public:
    TaskManager(vector<vector<int>>& tasks) {
        for (int i = 0; i < tasks.size(); i++) {
            usermap[tasks[i][0]].insert({tasks[i][1], tasks[i][2]});
            taskmap[tasks[i][1]].insert({tasks[i][0], tasks[i][2]});
            priormap[-(tasks[i][2])].insert({-(tasks[i][1]), tasks[i][0]});
        }
    }

    void add(int userId, int taskId, int priority) {
        usermap[userId].insert({taskId, priority});
        priormap[-priority].insert({-taskId, userId});
        taskmap[taskId].insert({userId, priority});
    }

    void edit(int taskId, int newPriority) {
        auto it =
            taskmap[taskId].begin(); // get iterator to first {userId, priority}
        int userId = it->first;
        int priority = it->second;

        usermap[userId].erase({taskId, priority});
        usermap[userId].insert({taskId, newPriority});

        priormap[-priority].erase({-taskId, userId});
        if (priormap[-priority].empty())
            priormap.erase(-priority);
        priormap[-newPriority].insert({-taskId, userId});

        taskmap[taskId].erase(it);
        taskmap[taskId].insert({userId, newPriority});
    }

    void rmv(int taskId) {
        auto it =
            taskmap[taskId].begin(); // get iterator to first {userId, priority}
        int userId = it->first;
        int priority = it->second;

        usermap[userId].erase({taskId, priority});
        priormap[-priority].erase({-taskId, userId});
        if (priormap[-priority].empty())
            priormap.erase(-priority);
        taskmap.erase(taskId);
    }

    int execTop() {
        if (priormap.empty())
            return -1;

        auto it = priormap.begin();      
        int currPriority = -(it->first);
        auto taskIt =
            it->second
                .begin(); 
        int currTask = -(taskIt->first);
        int currUser = taskIt->second;

       
        usermap[currUser].erase({currTask, currPriority});

       
        taskmap[currTask].erase({currUser, currPriority});
        taskmap.erase(currTask);

        
        it->second.erase(taskIt);
        if (it->second.empty())
            priormap.erase(it);

        return currUser;
    }
};

/**
 * Your TaskManager object will be instantiated and called as such:
 * TaskManager* obj = new TaskManager(tasks);
 * obj->add(userId,taskId,priority);
 * obj->edit(taskId,newPriority);
 * obj->rmv(taskId);
 * int param_4 = obj->execTop();
 */
