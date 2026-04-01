struct Robot {
    int position;
    int health;
    char direction;
    int index;
};
class Solution {
public:
    vector<int> survivedRobotsHealths(vector<int>& positions,
                                      vector<int>& healths, string directions) {
        int n = positions.size();
        vector<Robot> robots(n);
        for (int i = 0; i < n; i++) {
            robots[i] = {positions[i], healths[i], directions[i], i};
        }
        sort(robots.begin(), robots.end(), [](const Robot& a, const Robot& b) {
            return a.position < b.position;
        });
        stack<Robot> st;

        for (auto& current : robots) {
            if (current.direction == 'R') {
                st.push(current);
                continue;
            }
            while (!st.empty() && st.top().direction == 'R' &&
                   current.health > 0) {
                if (st.top().health > current.health) {
                    st.top().health -= 1;
                    current.health = 0;

                } else if (st.top().health < current.health) {
                    st.top().health = 0;
                    st.pop();
                    current.health -= 1;
                } else {
                    st.top().health = 0;
                    st.pop();
                    current.health = 0;
                }
            }
            if (current.health > 0) {
                st.push(current);
            }
        }
        vector<Robot> survivors;
        while (!st.empty()) {
            survivors.push_back(st.top());
            st.pop();
        }
        sort( survivors.begin(),  survivors.end(),
             [](const Robot& a, const Robot& b) { return a.index < b.index; });
        vector<int> res;
        for (auto& curr :  survivors) {
            if (curr.health > 0) {
                res.push_back(curr.health);
            }
        }
        return res;
    }
};
