// Problem : https://leetcode.com/problems/reverse-linked-list-ii/submissions/

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
    ListNode* rev(ListNode* head, int k) {
	ListNode* curr = head;
	ListNode* prev = nullptr;
	ListNode* next;
	int cnt = 0;
	while(++cnt <= k && curr) {
		next = curr->next;
		curr->next = prev;
		prev = curr;
		curr = next;
	}
	if(head) head->next = curr;
	return prev;
}

ListNode* revRange(ListNode* head, int left, int right) {
	ListNode* curr = head;
	ListNode* prev = nullptr;
	int pos = 0;
	while(++pos < left && curr) {
		prev = curr;
		curr = curr->next;
	}
	if(!prev){
        return rev(curr, right-left+1);
    } 
    prev->next = rev(curr, right-left+1);
	return head;
}
    // 1 -> 2 -> 3-> 4 -> 5 -> Null
    ListNode* reverseBetween(ListNode* head, int left, int right) {
        return revRange(head, left, right);
    }
};
