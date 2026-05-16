/**
 * @file test-merge-two-sorted-lists.cpp
 * @author Alfonso Castillo Orozco
 * @brief Testing solution "src/21-merge-two-sorted-lists".
 * @version 0.1
 * @date May 2026
 */

#include <gtest/gtest.h>
#include <vector>
#include <unordered_set>
#include "../../src/21-merge-two-sorted-lists/merge-two-sorted-lists.cpp"

// Input/Output Struct (Template)
struct TestInputParam {
    // Inputs
    std::vector<int> vector_linked_list1;
    std::vector<int> vector_linked_list2;
    // Expected Output
    std::vector<int> vector_expected_mergeTwoLists;
};

// Fixture Class: Solution Object + Input/Output Template
class SolutionParameterizedTestFixture : public ::testing::TestWithParam<TestInputParam> {
protected:
    Solution solution;

    ListNode* head = nullptr;

    ListNode* vectorToLinkedList(std::vector<int>& vector_linked_list) {
        if (vector_linked_list.empty()) return nullptr;

        head = new ListNode(vector_linked_list[0]);
        ListNode* current_node = head;

        for(size_t i = 1; i < vector_linked_list.size(); ++i ) {
            current_node->next = new ListNode(vector_linked_list[i]);
            current_node = current_node->next;
        }

        return head;
    }

    ListNode* vectorToLinkedListWithCycleOption(std::vector<int>& vector_linked_list, int pos) {
        // Linked List Without Cycle
        if (pos == -1) return vectorToLinkedList(vector_linked_list);
        
        // Linked List With Cycle
        if (vector_linked_list.empty()) return nullptr;

        head = new ListNode(vector_linked_list[0]);
        ListNode* current_node = head;
        ListNode* pos_node = head;

        for(size_t i = 1; i < vector_linked_list.size(); ++i ) {
            current_node->next = new ListNode(vector_linked_list[i]);
            current_node = current_node->next;

            if (pos >= 0 && (size_t)pos == i) pos_node = current_node;
        }

        current_node->next = pos_node;

        return head;
    }

    std::vector<int> linkedListToVector(ListNode* linked_list) {
        std::vector<int> vector_linked_list = {};

        if (linked_list == nullptr) return vector_linked_list;
        
        ListNode* current_node = linked_list;

        while (current_node != nullptr) {
            vector_linked_list.push_back(current_node->val);
            current_node = current_node->next;
        }

        return vector_linked_list;
    }

    // TearDown() is GTest "Destructor": Safely executed even if test fails. SetUp(): similar but for initialization.
    void TearDown() override {
        ListNode* current_node = head;
        std::unordered_set<ListNode*> visited_node = {}; // In case of a cycle, there is no nullptr: if the node is visited twice no "delete"

        while((current_node != nullptr) && (visited_node.find(current_node) == visited_node.end())) {
            ListNode* next_node = current_node->next;
            visited_node.insert(current_node); // In case of a cycle, to not "delete" twice the same node: Error
            delete current_node;
            current_node = next_node;
        }

        head = nullptr;
    }

};

// Test Parameterized: 21-merge-two-sorted-lists (src folder)
TEST_P(SolutionParameterizedTestFixture, MergeTwoLists) {
  // 1- Arrange: Retrieve Struct TestInputParam
  auto test_param = GetParam();
  ListNode* list1 = vectorToLinkedList(test_param.vector_linked_list1);
  ListNode* list2 = vectorToLinkedList(test_param.vector_linked_list2);
  
  // 2- Act: vector_actual_mergeTwoLists
  ListNode* actual_mergeTwoLists = solution.mergeTwoLists(list1, list2);
  std::vector<int> vector_actual_mergeTwoLists = linkedListToVector(actual_mergeTwoLists);

  // 3- Assert: vector_actual_mergeTwoLists vs vector_expected_mergeTwoLists
  EXPECT_EQ(vector_actual_mergeTwoLists, test_param.vector_expected_mergeTwoLists);
}

// Test Instantiated: Values to be Injected
INSTANTIATE_TEST_SUITE_P(
    MergeTwoListsTest,
    SolutionParameterizedTestFixture,
    ::testing::Values(
        // Test Cases from respective src README.md
        TestInputParam{{1,2,4}, {1,3,4}, {1,1,2,3,4,4}},
        TestInputParam{{}, {}, {}},
        TestInputParam{{}, {0}, {0}}
    )
);
