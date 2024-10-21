class Solution {
public:
    int maxcount;
    int maxUniqueSplit(string s) {
        maxcount = 0;
        unordered_set<string>st;
        backtrack(s,st,0);
        return maxcount;
    }
    void backtrack(string s,unordered_set<string>st,int index){
        int n = s.length();
        if(index == n){
            int v = st.size();
            maxcount = max(maxcount,v);
            return;
        }
       
        for(int i = index;i < n;i++){
           string sub = s.substr(index, i - index + 1); 
            if(!st.contains(sub)){
                st.insert(sub);
                backtrack(s,st,i+1);
                st.erase(sub);
            }
           
        }
    }
};
