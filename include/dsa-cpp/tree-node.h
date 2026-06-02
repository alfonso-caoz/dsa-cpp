/**
 * @file tree-node.h
 * @author Alfonso Castillo Orozco
 * @brief Header for Tree structures.
 * @version 0.1
 * @date May 2026
 */

#ifndef TREE_NODE_H
#define TREE_NODE_H

#include <vector>

 // Definition for a binary tree node.
 struct TreeNode {
     int val;
     TreeNode *left;
     TreeNode *right;
     TreeNode() : val(0), left(nullptr), right(nullptr) {}
     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 };

// Definition for a Node in non-binary trees.
class Node {
public:
    int val;
    std::vector<Node*> children;

    Node() {}

    Node(int _val) {
        val = _val;
    }

    Node(int _val, std::vector<Node*> _children) {
        val = _val;
        children = _children;
    }
};

#endif
