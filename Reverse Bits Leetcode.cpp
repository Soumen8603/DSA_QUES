 int reverseBits(int n) {
        string binary = "";
        for(int i = 31;i >= 0;i--){
            int bit = (n >> i) & 1;
            binary += (bit + '0');
        }
        int len = binary.length();
        int decimal = 0;
        for(int i = 0;i < len;i++){
            if(binary[i] == '1'){
            decimal += (1 << i);
            }
        }
        return decimal;
    }
