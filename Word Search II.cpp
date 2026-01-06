class TrieNode {
public:
    TrieNode* children[26];
    bool isWord;

    TrieNode() {
        isWord = false;
        for (int i = 0; i < 26; i++) {
            children[i] = nullptr;
        }
    }

    void addWord(std::string word) {
        TrieNode* cur = this;

        for (char c : word) {
            int index = c - 'a';

            if (cur->children[index] == nullptr) {
                cur->children[index] = new TrieNode();
            }

            cur = cur->children[index];
        }

        cur->isWord = true;
    }
};

class Solution {
    private:
    void dfs(int r, int c, int rows, int cols, vector<vector<char>>& board,
             TrieNode* node, string word, set<string>& ans,
             vector<vector<bool>>& visited) {
        if (r < 0 || c < 0 || r == rows || c == cols ||
            node->children[board[r][c] - 'a'] == nullptr ||
            visited[r][c] == true) {
            return;
        }
        visited[r][c] = true;
        node = node->children[board[r][c] - 'a'];
        word += board[r][c];
        if (node->isWord)
            ans.insert(word);
        dfs(r + 1, c, rows, cols, board, node, word, ans, visited);
        dfs(r - 1, c, rows, cols, board, node, word, ans, visited);
        dfs(r, c + 1, rows, cols, board, node, word, ans, visited);
        dfs(r, c - 1, rows, cols, board, node, word, ans, visited);
        visited[r][c] = false;
    }

public:
    vector<string> findWords(vector<vector<char>>& board,
                             vector<string>& words) {
        TrieNode* root = new TrieNode();

        for (int i = 0; i < words.size(); i++) {
            root->addWord(words[i]);
        }
        set<string> res;
        int rows = board.size(), cols = board[0].size();
        vector<vector<bool>> visited(rows, vector<bool>(cols, false));
        for (int i = 0; i < rows; i++) {
            for (int j = 0; j < cols; j++) {
                dfs(i, j,rows,cols, board,root, "", res, visited);
            }
        }
        return vector<string>(res.begin(), res.end());
    }
};
