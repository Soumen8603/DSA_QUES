void levelOrder(struct Node* &root, vector<int> &ans, int target)
    {
        if(!root)
        {
            return;
        }
        
        queue<pair<Node*, vector<int>>> q;
        q.push(make_pair(root, ans));
        
        while(!q.empty())
        {
            Node* front = q.front().first;
            int val = front->data;
            vector<int> res = q.front().second;
            q.pop();
            
            if(val == target)
            {
                ans = res;
                return;
            }
            
            res.push_back(val);
            
            if(front->left)
            {
                q.push(make_pair(front->left, res));
            }
            if(front->right)
            {
                q.push(make_pair(front->right, res));
            }
        }
    }
    // Function should return all the ancestor of the target node
    vector<int> Ancestors(struct Node *root, int target) {
        // Code here
        vector<int> ans;
        
        levelOrder(root, ans, target);
        
        reverse(ans.begin(), ans.end());
        
        return ans;
    }
