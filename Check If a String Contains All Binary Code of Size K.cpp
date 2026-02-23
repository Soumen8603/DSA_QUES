 bool hasAllCodes(string s, int k) {
        int stringLength = s.size();
        int totalPossibleCodes = 1 << k; 
      
       
        if (stringLength - k + 1 < totalPossibleCodes) {
            return false;
        }
      
        
        unordered_set<string> uniqueSubstrings;
      
        
        for (int i = 0; i + k <= stringLength; ++i) {
            
            uniqueSubstrings.insert(move(s.substr(i, k)));
        }
      
        
        return uniqueSubstrings.size() == totalPossibleCodes;
    }
