  int totalMoney(int n) {
        int monday_value = 1;
        int week_val = 28;
        int weeks = n / 7;
        int rem_days = n % 7;
        int cost = 0;
        for (int i = 1; i <= weeks; i++) {
            cost += week_val;
            week_val += 7;
        }
        monday_value += weeks;
        for (int i = 1; i <= rem_days; i++) {
            cost += monday_value;
            monday_value++;
        }
        return cost;
    }
