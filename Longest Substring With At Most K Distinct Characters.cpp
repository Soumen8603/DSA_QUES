#include<map>
int kDistinctChars(int k, string &str)
{
    // Write your code here
    map<char,int>mp;
    int max_length = 0;
    int left = 0;
    for(int right = 0;right < str.size();right++){
        mp[str[right]]++;
        while(mp.size() > k){
            char left_char = str[left];
            mp[left_char]--;
            if(mp[left_char] == 0){
                mp.erase(left_char);
            }
            left++;
        }
        max_length = max(max_length,right - left + 1);
    }
    return max_length;
}


