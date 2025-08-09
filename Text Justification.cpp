class Solution {
private:
    string makeline(vector<string>& words, int maxWidth,int i,int j,int eachblank,int extraspace){
        string line="";
        for(int k = i;k < j;k++){
            line += words[k];
            if(k == j-1){
                continue;
            }
            line.insert(line.size(),eachblank,' ');
            if(extraspace > 0){
                line += " ";
                extraspace--;
            }
        }
        while(line.length() < maxWidth){
            line += " ";
        }
        return line;
    }
public:
    vector<string> fullJustify(vector<string>& words, int maxWidth) {
        int n = words.size();
        vector<string>ans;
        int i = 0;

        while(i < n){
            int letterscount = words[i].length();
            int blank = 0;
            int j = i + 1;
            while(j < n && (words[j].length() + 1 + letterscount + blank) <= maxWidth){
                letterscount += words[j].length();
                blank++;
                j++;
            }
            int remaining = maxWidth - letterscount;
            int eachblank = (blank == 0)? 0 : remaining / blank;
            int extraspace = (blank == 0)? 0 : remaining % blank;
            if(j == n){
                eachblank = 1;
                extraspace = 0;
            }
            string line = makeline(words, maxWidth, i , j, eachblank, extraspace);
            
            ans.push_back(line);
            i = j;
            
        }
        return ans;
    }
};
