long long flowerGame(int n, int m) {
        long long odd_m = m / 2 + (m % 2);
        long long even_m = m / 2;

        long long odd_n = n / 2 + (n % 2);
        long long even_n = n / 2;

        long long total_pairs = odd_m * even_n + even_m * odd_n;
        return total_pairs;
    }
