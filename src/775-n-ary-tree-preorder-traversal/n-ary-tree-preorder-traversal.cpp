/*
// Definition for a Node.
class Node {
public:
    int val;
    vector<Node*> children;

    Node() {}

    Node(int _val) {
        val = _val;
    }

    Node(int _val, vector<Node*> _children) {
        val = _val;
        children = _children;
    }
};
*/

class Solution {
public:
    // Iterative Approach
    // Time Complexity O(n). Space Complexity O(n) [n: number of nodes. Stack with all nodes].
    vector<int> preorder(Node* root) {
        vector<int> ans;
        if (root == nullptr) return ans;

        stack<Node*> stackNodes;
        stackNodes.push(root);

        while (!stackNodes.empty()) {
            Node* temp = stackNodes.top(); // Returns the top element without removing it
            stackNodes.pop(); // Removes the element
            
            ans.push_back(temp->val);

            for (int i = temp->children.size()-1; i >= 0; --i) {
                stackNodes.push(temp->children[i]);
            }

        }

        return ans;
    }

/*
// RECURSIVE APPROACH
public:
    // Recursive Approach
    // Time Complexity O(n). Space Complexity O(n) [n: number of nodes. Implicit Auxiliary Recursive Stack].
    vector<int> preorder(Node* root) {
        vector<int> ans;
        aux_preorder(root, ans);
        return ans;
    }

private:
    // Auxiliary Preorder Method
    void aux_preorder(Node* root, vector<int>& ans) {
        if (root == nullptr) return;
        ans.push_back(root->val);
        for (auto child : root->children) aux_preorder(child, ans);
    }
*/

};
