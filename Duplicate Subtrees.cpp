string solve(unordered_map<string,int>&mp,vector<Node*>&ans,Node* root){
      if(!root)return "N";
      string s=to_string(root->data)+","+solve(mp,ans,root->left)+","+solve(mp,ans,root->right);
      mp[s]++;
      if(mp[s]==2){
          ans.push_back(root);
      }
      return s;
  }
    vector<Node*> printAllDups(Node* root) {
        // Code here
        vector<Node*>ans;
        unordered_map<string,int>mp;
        solve(mp,ans,root);
        return ans;
    }
