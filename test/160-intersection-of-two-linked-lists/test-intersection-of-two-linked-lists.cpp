/**
 * @file test-intersection-of-two-linked-lists.cpp
 * @author Alfonso Castillo Orozco
 * @brief Testing solution "src/160-intersection-of-two-linked-lists".
 * @version 0.1
 * @date May 2026
 */

#include <gtest/gtest.h>
#include <vector>
#include <unordered_set>
#include <tuple>
#include "../../src/160-intersection-of-two-linked-lists/intersection-of-two-linked-lists.cpp"

// Input/Output Struct (Template)
struct TestInputParam {
    // Inputs
    int intersectVal;
    std::vector<int> vector_linked_listA;
    std::vector<int> vector_linked_listB;
    int skipA;
    int skipB;
    // Expected Output
    std::vector<int> vector_expected_getIntersectionNode;
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

    std::tuple<ListNode*, ListNode*> vectorToLinkedListWithIntersectionOption(int intersectVal,
                                                                              std::vector<int>& vector_linked_listA,
                                                                              std::vector<int>& vector_linked_listB,
                                                                              int skipA, int skipB) {
        // Linked Lists Without Intersection
        if (intersectVal == 0) return {vectorToLinkedList(vector_linked_listA), vectorToLinkedList(vector_linked_listB)};
        
        // Linked Lists With Intersection
        std::vector<int> temp_subvector = (skipA <= 1) ? std::vector<int>{vector_linked_listA[0]} : std::vector<int>{vector_linked_listA.begin(), vector_linked_listA.begin() + skipA - 1}; // Unique Vector A
        ListNode* listA = vectorToLinkedList(temp_subvector); // Unique Linked List A at this point

        temp_subvector = (skipB <= 1) ? std::vector<int>{vector_linked_listB[0]} : std::vector<int>{vector_linked_listB.begin(), vector_linked_listB.begin() + skipB - 1}; // Unique Vector B                                                                       
        ListNode* listB = vectorToLinkedList(temp_subvector); // Unique Linked List B at this point

        temp_subvector = {vector_linked_listA.begin() + skipA, vector_linked_listA.end()}; // Shared Vector A and B
        ListNode* listSharedAB = vectorToLinkedList(temp_subvector); // Shared Linked List A and B

        ListNode* current_node_unique_A = listA;
        ListNode* current_node_unique_B = listB;

        while(current_node_unique_A->next != nullptr) current_node_unique_A = current_node_unique_A->next;
        while(current_node_unique_B->next != nullptr) current_node_unique_B = current_node_unique_B->next;                                                                       
        
        // List A and B Intersected
        current_node_unique_A->next = listSharedAB;
        current_node_unique_B->next = listSharedAB;

        return {listA, listB};
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

// Test Parameterized: 160-intersection-of-two-linked-lists (src folder)
TEST_P(SolutionParameterizedTestFixture, T160) {
  // 1- Arrange: Retrieve Struct TestInputParam
  auto test_param = GetParam();
  auto [listA, listB] = vectorToLinkedListWithIntersectionOption(test_param.intersectVal,
                                                                 test_param.vector_linked_listA,
                                                                 test_param.vector_linked_listB,
                                                                 test_param.skipA,
                                                                 test_param.skipB);
  
  // 2- Act: vector_actual_getIntersectionNode
  ListNode* actual_getIntersectionNode = solution.getIntersectionNode(listA, listB);
  // Just to return the Intersection node value, not the whole Linked List as Vector
  std::vector<int> vector_actual_getIntersectionNode = (actual_getIntersectionNode != nullptr) ? std::vector<int>{actual_getIntersectionNode->val} : std::vector<int>{}; // C++23: <Type>{}. Soon... C++26: {}

  // 3- Assert: vector_actual_getIntersectionNode vs vector_expected_getIntersectionNode
  EXPECT_EQ(vector_actual_getIntersectionNode, test_param.vector_expected_getIntersectionNode);
}

// Test Instantiated: Values to be Injected
INSTANTIATE_TEST_SUITE_P(
    GetIntersectionNodeTest,
    SolutionParameterizedTestFixture,
    ::testing::Values(
        // Test Cases from respective src README.md
        TestInputParam{8, {4,1,8,4,5}, {5,6,1,8,4,5}, 2, 3, {8}},
        TestInputParam{2, {1,9,1,2,4}, {3,2,4}, 3, 1, {2}},
        TestInputParam{0, {2,6,4}, {1,5}, 3, 2, {}}
    )
);
