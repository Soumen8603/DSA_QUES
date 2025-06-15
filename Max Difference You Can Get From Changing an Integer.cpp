int maxDiff(int num) {
        string s = to_string(num);
        char st1 = s[0];
        for (int i = 0; i < s.size(); i++) {
            if (s[i] != '9') {
                st1 = s[i];
                break;
            }
        }

        char st2 = s[0];
        int check = 0;
        for (int i = 0; i < s.size(); i++) {
            if (s[i] != '1' && s[i] != '0') {
                st2 = s[i];
                if (i != 0) {
                    check = 1;
                }
                break;
            }
        }
        string maxi, mini;
        for (int i = 0; i < s.size(); i++) {
            if (s[i] == st1) {
                maxi[i] = '9';
            } else {
                maxi[i] = s[i];
            }
        }

        for (int i = 0; i < s.size(); i++) {
            if (s[i] == st2) {
                if (check == 0) {
                    mini[i] = '1';
                } else {
                    mini[i] = '0';
                }
            } else {
                mini[i] = s[i];
            }
        }

        int maxii, minii;
        maxii = stoi(maxi);
        minii = stoi(mini);
        return maxii - minii;
    }
