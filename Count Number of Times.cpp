int numTeams(vector<int>& rating) {
        int n = rating.size();
        int count=0;

        for(int mid = 1;mid < n-1;mid++){
            int leftSmallerCount=0,rightGreaterCount=0;

            for(int i = 0;i < mid;i++){
                if(rating[i] < rating[mid])leftSmallerCount++;
            }

            for(int j = mid+1;j < n;j++){
                if(rating[j] > rating[mid])rightGreaterCount++;
            }

        //For Increasing Order
        count += leftSmallerCount * rightGreaterCount;

        int leftGreaterCount = mid - leftSmallerCount;

        int rightSmallerCount = n - mid - 1 - rightGreaterCount;

        count += leftGreaterCount * rightSmallerCount;   
        }

        return count;

    }
