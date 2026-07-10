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
    TreeNode* deleteNode(TreeNode* root, int key) {
        if(!root) return nullptr ; 
        if(root -> val == key)
        {
            return helper(root) ; 
        }
        TreeNode* dummy = root ; 
        while(root != nullptr)
        {
            if(root -> val <= key)
            {
                // keep on searching in the right side
                if(root -> right != nullptr && root -> right -> val == key )
                {
                    root -> right = helper(root -> right); 
                    break ;
                }
                else{
                    root = root -> right ; 
                }
            }
            else{
                // keep on searching in the left side 
                if(root -> left != nullptr && root -> left -> val == key)
                {
                    root -> left = helper(root -> left) ; 
                    break ; 
                }
                else{
                    root = root -> left ; 
                }
            }
        }
        return dummy ; 
    }

    TreeNode* helper(TreeNode* root)
    {
        if(root -> left == nullptr) { return root -> right ;}
        if(root -> right == nullptr) {return root -> left ;}

        TreeNode* rightChild = root -> right ; 
        TreeNode* lastRightNode = findLastRightNode(root -> left ) ; // 4
        lastRightNode -> right = rightChild ; 
        return root -> left ; 
    }

    TreeNode* findLastRightNode (TreeNode* root){
        if(root -> right == nullptr)
        {
            return root ;
        }
        return findLastRightNode(root -> right );

    }

};