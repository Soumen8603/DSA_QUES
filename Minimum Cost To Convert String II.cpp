class TrieNode {
public:
    TrieNode* children[26];
    int nodeIndex = -1;

    TrieNode() {
        fill(children, children + 26, nullptr);
    }
};

class Solution {
private:
    static constexpr long long INF = 1LL << 60;
    TrieNode* trieRoot;
    int nextNodeIndex;
    vector<vector<long long>> costGraph;
    string sourceStr;
    string targetStr;
    vector<long long> memo;

    int insertIntoTrie(const string& word) {
        TrieNode* currentNode = trieRoot;
        for (char ch : word) {
            int charIndex = ch - 'a';
            if (currentNode->children[charIndex] == nullptr) {
                currentNode->children[charIndex] = new TrieNode();
            }
            currentNode = currentNode->children[charIndex];
        }
        if (currentNode->nodeIndex < 0) {
            currentNode->nodeIndex = nextNodeIndex++;
        }
        return currentNode->nodeIndex;
    }

    long long computeMinCost(int position) {
        if (position >= sourceStr.length()) {
            return 0;
        }
        if (memo[position] != -1) {
            return memo[position];
        }

        long long minCost = (sourceStr[position] == targetStr[position]) ? 
                             computeMinCost(position + 1) : INF;

        TrieNode* sourceNode = trieRoot;
        TrieNode* targetNode = trieRoot;

        for (int endPos = position; endPos < sourceStr.length(); ++endPos) {
            sourceNode = sourceNode->children[sourceStr[endPos] - 'a'];
            targetNode = targetNode->children[targetStr[endPos] - 'a'];

            if (sourceNode == nullptr || targetNode == nullptr) {
                break;
            }

            if (sourceNode->nodeIndex >= 0 && targetNode->nodeIndex >= 0) {
                long long transformCost = costGraph[sourceNode->nodeIndex][targetNode->nodeIndex];
                if (transformCost < INF) {
                    long long subCost = computeMinCost(endPos + 1);
                    if (subCost < INF) {
                        minCost = min(minCost, transformCost + subCost);
                    }
                }
            }
        }

        return memo[position] = minCost;
    }

public:
    long long minimumCost(string source, string target, vector<string>& original, 
                          vector<string>& changed, vector<int>& cost) {
        trieRoot = new TrieNode();
        nextNodeIndex = 0;
        int m = original.size();
        
        costGraph = vector<vector<long long>>(m * 2, vector<long long>(m * 2, INF));
        for (int i = 0; i < m * 2; ++i) costGraph[i][i] = 0;

        for (int i = 0; i < m; ++i) {
            int u = insertIntoTrie(original[i]);
            int v = insertIntoTrie(changed[i]);
            costGraph[u][v] = min(costGraph[u][v], (long long)cost[i]);
        }

        for (int k = 0; k < nextNodeIndex; ++k) {
            for (int i = 0; i < nextNodeIndex; ++i) {
                if (costGraph[i][k] == INF) continue;
                for (int j = 0; j < nextNodeIndex; ++j) {
                    if (costGraph[k][j] < INF) {
                        costGraph[i][j] = min(costGraph[i][j], costGraph[i][k] + costGraph[k][j]);
                    }
                }
            }
        }

        sourceStr = source;
        targetStr = target;
        memo.assign(source.length(), -1);

        long long finalResult = computeMinCost(0);
        return finalResult >= INF ? -1 : finalResult;
    }
};
