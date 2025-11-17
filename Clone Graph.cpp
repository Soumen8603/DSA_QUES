/*
// Definition for a Node.
class Node {
public:
    int val;
    vector<Node*> neighbors;
    Node() {
        val = 0;
        neighbors = vector<Node*>();
    }
    Node(int _val) {
        val = _val;
        neighbors = vector<Node*>();
    }
    Node(int _val, vector<Node*> _neighbors) {
        val = _val;
        neighbors = _neighbors;
    }
};
*/

class Solution {
public:
    Node* cloneGraph(Node* node) {
        if(node == nullptr){
            return nullptr;
        }
        map<Node*,Node*>oldToNew;
        queue<Node*>q;
        Node* cloneStartNode = new Node(node -> val);
        oldToNew[node] = cloneStartNode;
        q.push(node);
        while(!q.empty()){
            Node* original = q.front();
            q.pop();
            Node* currentClone = oldToNew[original];
            for(Node* originalNeighbor : original -> neighbors){
                if(oldToNew.find(originalNeighbor) == oldToNew.end()){
                    Node* clonedNeighbor = new Node(originalNeighbor -> val);
                    oldToNew[originalNeighbor] = clonedNeighbor;
                    q.push(originalNeighbor);
                }
                currentClone -> neighbors.push_back(oldToNew[originalNeighbor]);
            }
        }
        return cloneStartNode;
    }
};
