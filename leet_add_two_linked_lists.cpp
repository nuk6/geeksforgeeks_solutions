
// Q: https://leetcode.com/problems/add-two-numbers

/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {
public:
    
ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        ListNode* l3,*root, *p1,*p2;
        p1 = l1, p2 = l2;
        l3 = new ListNode(-1);
        root = l3;
        int data,carry = 0;
        while((p1)&&(p2)){
            data = p1->val+p2->val +carry;
            if(data > 9){
                cout << data << endl;
                carry = (data/10);
                data = data%10;
                cout << "Carry "<<carry << endl;
            } else carry = 0;
            l3->next = new ListNode(data);
            p1 = p1->next;
            p2 = p2->next;
            l3 = l3->next;
        }
        while(p1){
            data = p1->val+carry;
            if(data > 9){
                carry = (data/10);
                data = data%10;
            } else carry = 0;
            l3->next = new ListNode(data);
            p1 = p1->next;
            l3 = l3->next;
        }
        while(p2){
            data = p2->val+carry;
            if(data > 9){
                carry = (data/10);
                data = data%10;
            } else carry = 0;
            l3->next = new ListNode(data);
            p2 = p2->next;
            l3 = l3->next;
        }
        cout << carry << endl;
        if(carry) l3->next = new ListNode(carry);
        return root->next;
}
};
