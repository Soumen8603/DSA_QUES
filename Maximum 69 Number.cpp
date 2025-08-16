int maximum69Number (int num) {
        string s = to_string(num);       
        for (char &c : s) {              
            if (c == '6') {               // if we find a '6'
                c = '9';                  // change it to '9'
                break;                    // stop after changing the first one
            }
        }
        return stoi(s);                   // turn the string back into a number
    }
