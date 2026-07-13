/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
public:
    void helper(TreeNode* root , vector<int>& store)
    {
        if(!root) return  ; 
        helper(root -> left, store) ; 
        store.push_back(root->val); 
        helper(root -> right, store);
    }
    int kthSmallest(TreeNode* root, int k) {
        vector<int> store;
        helper(root , store) ; 
       
        return store[k-1] ; 
    }
};