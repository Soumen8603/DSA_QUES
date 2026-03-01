int minPartitions(string n) {
        int maxDigit = 0;

        for (char& digit : n) {

            maxDigit = max(maxDigit, digit - '0');
        }

        return maxDigit;
    }
