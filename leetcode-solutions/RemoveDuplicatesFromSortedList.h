#pragma once

#include "common.h"

//  Given a sorted linked list, delete all duplicates such that each element appear only once.
//  
//  For example,
//  Given 1->1->2, return 1->2.
//  Given 1->1->2->3->3, return 1->2->3.

/**
* Definition for singly-linked list.
*/

struct ListNode {
     int val;
     ListNode *next;
     ListNode(int x) : val(x), next(NULL) {}
};

ListNode *deleteDuplicates(ListNode *head) {
	ListNode* currentNode = head;
	if (head == NULL) return head;
	while (currentNode->next != NULL) {
		if (currentNode->val == currentNode->next->val) {
			ListNode * temp = currentNode->next;
			currentNode->next = temp->next;
			delete temp;
		}
		else
			currentNode = currentNode->next;
	}
	return head;
}