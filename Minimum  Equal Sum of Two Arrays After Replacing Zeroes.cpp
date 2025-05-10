 long long minSum(vector<int>& nums1, vector<int>& nums2) {
        long long sum1=0,countzero1=0;
        for(int i = 0;i < nums1.size();i++){
            sum1+=nums1[i];
            if(nums1[i]==0){
                countzero1++;
            }
        }

        long long sum2=0,countzero2=0;
        for(int i = 0;i < nums2.size();i++){
            sum2+=nums2[i];
            if(nums2[i]==0){
                countzero2++;
            }
        }

        long long total1 = sum1+countzero1;
        long long total2 = sum2+countzero2;
        if(total1 > total2 && countzero2==0){
            return -1;
        }
        else if(total2 > total1 && countzero1==0){
            return -1;
        }
        else{
            return max(total1,total2);
        }
    }
