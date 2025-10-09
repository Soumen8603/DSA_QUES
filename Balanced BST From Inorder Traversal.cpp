#include <iostream>
#include <vector>
#include <string>
#include <queue>
using namespace std;

struct TreeNode {
    int val;
    TreeNode* left;
    TreeNode* right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

TreeNode* buildBstHelper(vector<int>& nums,int start,int end){
    if(start > end){
        return nullptr;
    }
    int mid = start + (end - start) / 2;
    TreeNode* root = new TreeNode(nums[mid]);
    root->left = buildBstHelper(nums,start,mid-1);
    root->right = buildBstHelper(nums,mid+1,end);
    return root;
}
TreeNode* sortedArrayToBST(vector<int>& nums) {
    // Write your logic here to convert sorted array to a balanced BST.
    int start = 0;
    int end = nums.size() - 1;
    return buildBstHelper(nums,start,end);
}

string treeNodeToString(TreeNode* root) {
    // Write your logic here to convert the BST to a level order serialized string.
    if(!root){
        return "";
    }
    string ans = "";
    queue<TreeNode*>q;
    q.push(root);
    while(!q.empty()){
        TreeNode* node = q.front();
        q.pop();
        if(node != nullptr){
            ans += " ";
            ans += to_string(node -> val);
            q.push(node -> left);
            q.push(node -> right);
        }
    }
    
    return ans;
}

int main() {
    int n;
    cin >> n;
    vector<int> arr(n);
    for (int i = 0; i < n; ++i) {
        cin >> arr[i];
    }
    TreeNode* root = sortedArrayToBST(arr);
    string result = treeNodeToString(root);
    cout << result << endl;
    return 0;
}
