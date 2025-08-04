int totalFruit(vector<int>& fruits) {
        int maxi = INT_MIN;
        int first_index = 0;
        int second_index;
        int change = 1;
        int find_second = 0;
        int count = 1;
        for (int i = 1; i < fruits.size(); i++) {
            if (fruits[i] == fruits[first_index]) {
                count++;
                if (change == 0) {
                    change = 1;
                    first_index = i;
                }
            } else if (find_second == 0 || fruits[i] == fruits[second_index]) {
                count++;

                find_second = 1;

                if (change == 1) {
                    change = 0;
                    second_index = i;
                }
            } else {
                maxi = max(maxi, count);
                count = 0;

                int addi = (fruits[i - 1] == fruits[first_index])
                               ? (i - first_index)
                               : (i - second_index);
                count += addi + 1;
                first_index = i - 1;
                second_index = i;
                change = 0;
            }
        }
        maxi = max(maxi, count);
        return maxi;
    }
