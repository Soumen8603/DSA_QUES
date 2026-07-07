long long sumAndMultiply(int n) {
        long long sum = 0;
        long long number = 0;

        while(n > 0){
            int digit = n % 10;
            n = n / 10;
            if(digit != 0){
                sum += digit;
                number = ((number * 10) + digit);
            }
        }
        long long num = 0;
        while(number > 0){
            int digit = number % 10;
            number = number / 10;
            num = (num * 10) + digit;
        }
        return num * sum;
    }
