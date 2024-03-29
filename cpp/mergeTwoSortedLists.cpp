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
    ListNode* mergeTwoLists(ListNode* l1, ListNode* l2) {
        ListNode* h = new ListNode(0);
        ListNode* ptr = h;
        if(!l1){
            return l2;
        }
        if(!l2){
            return l1;
        }
        while(l1 || l2){
            if(l1->val<l2->val){
                h->next=l1;
                h=h->next;
                l1=l1->next;
            }else{
                h->next=l2;
                h=h->next;
                l2=l2->next;
            }
            if(!l1){
                h->next=l2;
                break;
            }else if(!l2){
                h->next = l1;
                break;
            }
        }
        return ptr->next;
    }
};