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
    void inOrder(TreeNode* root , vector<int>& store)
    {
        if(!root) return ; 
        inOrder(root -> left, store);
        store.push_back(root -> val);
        inOrder(root -> right , store);

    }

    int minDiffInBST(TreeNode* root) {
      vector<int> store ; 
      inOrder(root , store) ; 
      int minDiff = INT_MAX ; 
      for(int i = 1 ; i < store.size(); i++)
      {
        int diff = store[i] - store[i - 1] ; 
        minDiff = min(minDiff , diff) ; 
      }
      return minDiff ; 
    }

    

};