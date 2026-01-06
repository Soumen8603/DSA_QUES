class TrieNode{
public:
    TrieNode* children[26];
    bool isLeaf;
    TrieNode(){
        isLeaf = false;
        for(int i = 0;i < 26;i++){
            children[i] = nullptr;
        }
    }
};
class WordDictionary {
private:
    TrieNode* root = new TrieNode();
    bool dfs(TrieNode* curr,string &word,int index){
        if(index == word.size())return curr->isLeaf;;
        
        char c = word[index];
        if(c == '.'){
            for(int i = 0;i < 26;i++){
                if(curr -> children[i] != nullptr){
                    if(dfs(curr->children[i],word,index+1)){
                        return true;
                    }
                }
            }
            return false;
        }
        else{
            int charIdx = c - 'a';
            if(curr -> children[charIdx] == nullptr){
                return false;
            }
            return dfs(curr -> children[charIdx],word,index+1);
        }
    }
public:
    WordDictionary() {
        
    }
    
    void addWord(string word) {
        TrieNode* curr = root;
        for(char c : word){
            if(curr->children[c-'a'] == nullptr){
                TrieNode* newNode = new TrieNode();
                curr->children[c-'a'] = newNode;
            }
            curr = curr -> children[c-'a'];
        }
        curr -> isLeaf = true;
    }
    
    bool search(string word) {
        TrieNode* curr = root;
        return dfs(curr,word,0);
    }
};

/**
 * Your WordDictionary object will be instantiated and called as such:
 * WordDictionary* obj = new WordDictionary();
 * obj->addWord(word);
 * bool param_2 = obj->search(word);
 */
