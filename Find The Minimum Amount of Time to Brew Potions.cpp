long long minTime(vector<int>& skill, vector<int>& mana) {
        int m = skill.size();
        int n = mana.size();

       
        vector<long long> lastExecuted(m, 0);

        lastExecuted[0] = (long long)skill[0] * mana[0];
        for (int i = 1; i < m; i++) {
            lastExecuted[i] =
                lastExecuted[i - 1] + (long long)skill[i] * mana[0];
        }

        
        if (n == 1) {
            return lastExecuted[m - 1]; 
        }

      
        for (int i = 1; i < n; i++) {
            
            long long start = 0; 

            long long prev_potion_cumulative_time = 0;
            long long current_potion_cumulative_time = 0;

            for (int j = 0; j < m; j++) {
                prev_potion_cumulative_time = lastExecuted[j];

                long long delay_needed = prev_potion_cumulative_time -
                                         current_potion_cumulative_time;
                start = max(start, delay_needed);

                current_potion_cumulative_time += (long long)skill[j] * mana[i];
            }

            current_potion_cumulative_time = 0;
            for (int j = 0; j < m; j++) {
                current_potion_cumulative_time += (long long)skill[j] * mana[i];
                lastExecuted[j] = start + current_potion_cumulative_time;
            }
        }

        return lastExecuted[m - 1];
    }
