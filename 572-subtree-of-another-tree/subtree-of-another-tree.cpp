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
    // Time Complexity O(n^2) [O(n*m)]. Space Complexity O(n) [O(n) + O(m) = O(n+m)].
    // Note: Time Complexity could be improved as O(n+m) by serializing both trees, but maybe it is not the intention here.
    // Look at "449. Serialize and Deserialize BST". I recommend asking the interviewer if it is acceptable serializing.
    bool isSubtree(TreeNode* root, TreeNode* subRoot) {
        if (root == nullptr) return false;
        if (isSame(root, subRoot)) return true;
        return isSubtree(root->left, subRoot) || isSubtree(root->right, subRoot);
    }

private:
    // Helper Function: Two trees are the same.
    bool isSame(TreeNode* s, TreeNode* t) {
        if (s == nullptr && t == nullptr) return true;
        if (s == nullptr || t == nullptr) return false;
        
        // Previous two lines in one, but it is harder to follow, not explicit for the interviewer.
        //if (s == nullptr || t == nullptr) return s==t;
        
        // Explicitly
        //if (s->val != t->val) return false;
        //return isSame(s->left, t->left) && isSame(s->right, t->right);
        
        return (s->val == t->val) && isSame(s->left, t->left) && isSame(s->right, t->right);
    }

};
