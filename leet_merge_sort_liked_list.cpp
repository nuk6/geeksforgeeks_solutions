// P : https://leetcode.com/problems/sort-list/
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
    ListNode* getMid(ListNode* head) {
	ListNode* slow = head;
	ListNode* fast = head;
	while(fast && fast->next && fast->next->next) {
		slow = slow->next;
		fast = fast->next->next;
	}
	return slow;
}
    ListNode* sort(ListNode* head) {
	if(!head || !head->next) return head; // single node or null
	ListNode* mid = getMid(head);
	ListNode* left = head;
	ListNode* right = mid->next;
	mid->next = nullptr;
	left = sort(left);
	right = sort(right);
	ListNode* res = merge(left, right);
	return res;
}
    ListNode* merge(ListNode* l1, ListNode* l2) {
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
	res = res->next;
	return res;
}
    ListNode* sortList(ListNode* head) {
        ListNode* sorted = sort(head);
        return sorted;
    }
};
