// P : https://leetcode.com/problems/merge-two-sorted-lists/
/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
class Solution {
public:
    ListNode* mergeTwoLists(ListNode* l1, ListNode* l2) {
        ListNode* res = new ListNode(-1);
	ListNode* temp = res;
	ListNode* c1 = l1;
	ListNode* c2 = l2;
	while(c1 && c2) {
		if(c1->val < c2->val) {
			temp->next = c1;
			c1 = c1->next;
		} else {
			temp->next = c2;
			c2 = c2->next;
		}
		temp = temp->next;
	}
	while(c1) {
		temp->next = c1;
		c1 = c1->next;
		temp = temp->next;
	}
	while(c2) {
		temp->next = c2;
		c2 = c2->next;
		temp = temp->next;
	}
	return res->next;
    }
};
