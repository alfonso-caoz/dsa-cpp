/**
 * @file linked-list-node.h
 * @author Alfonso Castillo Orozco
 * @brief Header for ListNode struct.
 * @version 0.1
 * @date May 2026
 */

#ifndef LINKED_LIST_NODE_H
#define LINKED_LIST_NODE_H

 // Definition for singly-linked list.
 struct ListNode {
     int val;
     ListNode *next;
     ListNode() : val(0), next(nullptr) {}
     ListNode(int x) : val(x), next(nullptr) {}
     ListNode(int x, ListNode *next) : val(x), next(next) {}
 };

#endif
