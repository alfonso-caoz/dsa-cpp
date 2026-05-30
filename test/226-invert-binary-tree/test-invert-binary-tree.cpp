/**
 * @file test-invert-binary-tree.cpp
 * @author Alfonso Castillo Orozco
 * @brief Testing solution "src/226-invert-binary-tree".
 * @version 0.1
 * @date May 2026
 */

#include <gtest/gtest.h>
#include <vector>
#include <queue>
#include <optional>
#include <unordered_set>
#include "../../src/226-invert-binary-tree/invert-binary-tree.cpp"

// Input/Output Struct (Template)
struct TestInputParam {
    // Input
    std::vector<std::optional<int>> vector_root;
    // Expected Output
    std::vector<std::optional<int>> vector_expected_invertTree;
};

// Fixture Class: Solution Object + Input/Output Template
class SolutionParameterizedTestFixture : public ::testing::TestWithParam<TestInputParam> {
protected:
    Solution solution;

    TreeNode* root = nullptr;

    TreeNode* vectorToTree(std::vector<std::optional<int>>& vector_tree) {
        // Similar: (vector_tree[0] == std::nullopt) : (!vector_tree[0].has_value())
        if (vector_tree.empty() || vector_tree[0] == std::nullopt) return nullptr;

        root = new TreeNode(vector_tree[0].value());
        std::queue<TreeNode*> parent_without_assigned_child; // Until vector runs out of elements to be assigned as child to a remaining member in queue (last tree nodes)
        parent_without_assigned_child.push(root);

        size_t i = 1;
        while (i < vector_tree.size()) {
            // Possible Parent OR Last Node
            TreeNode* current_node = parent_without_assigned_child.front();
            parent_without_assigned_child.pop();

            // Current Left Child
            if (vector_tree[i].has_value()) { // Left is nullptr already, if it has a value create the left node. Added to create also no binary trees.
                current_node->left = new TreeNode(vector_tree[i].value());
                parent_without_assigned_child.push(current_node->left);
            }
            ++i;

            if (i >= vector_tree.size()) break; // Checking not going out of boundaries for following right child

            // Current Right Child
            if (vector_tree[i].has_value()) { // Right is nullptr already, if it has a value create the right node. Added to create also no binary trees.
                current_node->right = new TreeNode(vector_tree[i].value());
                parent_without_assigned_child.push(current_node->right);
            }
            ++i;
        }

        return root;
    }

    std::vector<std::optional<int>> treeToVector(TreeNode* tree) {
        if (tree == nullptr) return {};

        std::vector<std::optional<int>> vector_tree;
        std::queue<TreeNode*> parent_without_assigned_child; // Until tree runs out of nodes
        parent_without_assigned_child.push(tree);

        while (!parent_without_assigned_child.empty()) {
            // Possible Parent OR Last Node
            TreeNode* current_node = parent_without_assigned_child.front();
            parent_without_assigned_child.pop();

            vector_tree.push_back(current_node->val);

            if (current_node->left || current_node->right) { // If both nullptr, it makes no sense to add two nullopt in a vector

                // Current Left Child
                if (current_node->left) { // Left is not nullptr
                    parent_without_assigned_child.push(current_node->left);
                } else {
                    vector_tree.push_back(std::nullopt);
                }

                // Current Right Child
                if (current_node->right) { // Right is not nullptr
                    parent_without_assigned_child.push(current_node->right);
                } else {
                    vector_tree.push_back(std::nullopt);
                }

            }
        }

        return vector_tree;
    }

    // Helper to free tree nodes recursively
    void freeTree(TreeNode* tree) {
        if (!tree) return;
        freeTree(tree->left);  // free left subtree
        freeTree(tree->right); // free right subtree
        delete tree;           // free current node
    }

    // TearDown() is GTest "Destructor": Safely executed even if test fails. SetUp(): similar but for initialization.
    void TearDown() override {
        freeTree(root);
        root = nullptr;
    }

};

// Test Parameterized: 226-invert-binary-tree (src folder)
TEST_P(SolutionParameterizedTestFixture, InvertTree) {
  // 1- Arrange: Retrieve Struct TestInputParam
  auto test_param = GetParam();
  TreeNode* root = vectorToTree(test_param.vector_root);
  
  // 2- Act: vector_actual_invertTree
  TreeNode* actual_invertTree = solution.invertTree(root);
  std::vector<std::optional<int>> vector_actual_invertTree = treeToVector(actual_invertTree);

  // 3- Assert: vector_actual_invertTree vs vector_expected_invertTree
  EXPECT_EQ(vector_actual_invertTree, test_param.vector_expected_invertTree);
}

// Test Instantiated: Values to be Injected
INSTANTIATE_TEST_SUITE_P(
    InvertTreeTest,
    SolutionParameterizedTestFixture,
    ::testing::Values(
        // Test Cases from respective src README.md
        TestInputParam{{4,2,7,1,3,6,9}, {4,7,2,9,6,3,1}},
        TestInputParam{{2,1,3}, {2,3,1}},
        TestInputParam{{}, {}}
    )
);
