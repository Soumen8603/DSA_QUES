 int numWaterBottles(int numBottles, int numExchange) {
        int rem = numBottles;
        int result = numBottles;
        while(rem >= numExchange){

            int full = rem / numExchange;
            int extra = rem % numExchange;
            result += full;
            rem = full + extra;
             
        }
        return result;
    }
