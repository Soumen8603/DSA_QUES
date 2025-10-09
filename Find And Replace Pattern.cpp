#include <iostream>
#include <vector>
#include <string>
using namespace std;
vector<int> convert_count(string words){
    vector<int>ans;
    int n = words.size();
    int i = 0;
    while(i < n){
        char letter = words[i];
        int count = 1;
        int j = i + 1;
        if(j < n && words[j] == words[i]){
            while(j < n && words[j] == words[i]){
                count++;
                j++;
            }
        }
        ans.push_back(count);
        i = j;

    }
    return ans;
}
pair<int, vector<string>> find_and_replace_pattern(vector<string>& words, const string& pattern) {
    // Write your logic here.
    vector<int>pattern_count;
    pattern_count = convert_count(pattern);
    int count = 0;
    vector<string>res;
    for(int i = 0;i < words.size();i++){
        if(words[i].size() != pattern.size())continue;
        vector<int>word_pattern = convert_count(words[i]);
        if(word_pattern.size() != pattern_count.size())continue;
        if(word_pattern == pattern_count){
            count++;
            res.push_back(words[i]);
        }
    }
    pair<int, vector<string>>p1;
    p1.first = count;
    p1.second = res;
    return p1;
}

int main() {
    int n;
    cin >> n;
    vector<string> words(n);
    for (int i = 0; i < n; ++i) {
        cin >> words[i];
    }
    string pattern;
    cin >> pattern;
    
    auto result = find_and_replace_pattern(words, pattern);
    int matched_count = result.first;
    vector<string> matched_words = result.second;
    
    cout << matched_count << endl;
    if (matched_count > 0) {
        for (const auto& word : matched_words) {
            cout << word << " ";
        }
        cout << endl;
    }
    return 0;
}
