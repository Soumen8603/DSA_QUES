 string roundToNearest(string str) {
        // Complete the function
        int n = str.size();
    int last = str[n-1] - '0';
    
    if (last > 5 && n > 1) {
        int i = n - 2;
        while (i >= 0 && str[i] == '9') {
            str[i] = '0';  // Set the digit to 0 and continue to the previous digit
            i--;
        }
        
        if (i >= 0) {
            str[i] = char(str[i] + 1);  // Increment the first non-9 digit
        } else {
            str = "1" + str;  // If all digits are 9, prepend '1'
        }
        
        str[n-1] = '0';  // The last digit is rounded to 0
    } else if (last > 5 && n == 1) {
        str = "10";  // Special case for single-digit numbers
    } else {
        str[n-1] = '0';  // If last digit <= 5, just round down
    }

    return str;
        
    }
