int maxBottlesDrunk(int numBottles, int numExchange) {
        int result = numBottles;
        int rem = result;
        while(rem >= numExchange){
            result ++;
            rem = rem - numExchange + 1;
            numExchange ++;
           
        }
        return result;
    }
