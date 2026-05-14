/**
 * @file test-linked-list-cycle.cpp
 * @author Alfonso Castillo Orozco
 * @brief Testing solution "src/141-linked-list-cycle".
 * @version 0.1
 * @date May 2026
 */

#include <gtest/gtest.h>
#include <vector>
#include <unordered_set>
#include "../../src/141-linked-list-cycle/linked-list-cycle.cpp"

// Input/Output Struct (Template)
struct TestInputParam {
    // Inputs
    std::vector<int> vector_linked_list;
    int pos;
    // Expected Output
    bool expected_hasCycle;
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

// Test Parameterized: 141-linked-list-cycle (src folder)
TEST_P(SolutionParameterizedTestFixture, HasCycle) {
  // 1- Arrange: Retrieve Struct TestInputParam
  auto test_param = GetParam();
  head = vectorToLinkedListWithCycleOption(test_param.vector_linked_list, test_param.pos);
  
  // 2- Act: actual_hasCycle
  bool actual_hasCycle = solution.hasCycle(head);

  // 3- Assert: actual_hasCycle vs expected_hasCycle
  EXPECT_EQ(actual_hasCycle, test_param.expected_hasCycle);
}

// Test Instantiated: Values to be Injected
INSTANTIATE_TEST_SUITE_P(
    HasCycleTest,
    SolutionParameterizedTestFixture,
    ::testing::Values(
        // Test Cases from respective src README.md
        TestInputParam{{3,2,0,-4}, 1, true},
        TestInputParam{{1,2}, 0, true},
        TestInputParam{{1}, -1, false}
    )
);
